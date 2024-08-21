from hazm import *
import pandas as pd
import numpy as np
import re
from math import log2
from math import log1p
from math import log10
import alive_progress # for measuring time


normalizer = 10 ** 4

# transfer data from dataset to lists
def transfer_data(df):
    des = df["description"].values.tolist()
    book = df["title"].values.tolist()
    temp = []
    for x, y in zip(des, book):
        temp.append(x + ' ' + y)
    pattern = r'[^آ-ی|^\u0020|^\u200C]'
    result = list(map(lambda v: re.sub(pattern, '', v), temp))
    return result


train_df = pd.read_csv('./books_train.csv')
test_df = pd.read_csv('./books_test.csv')

# 0:"مدیریت و کسب و کار"
# 1:"رمان"
# 2:"کلیات اسلام"
# 3:"داستان کودک و نوجوانان"
# 4:"جامعه‌شناسی"
# 5:"داستان کوتاه"


train = {
    "مدیریت و کسب و کار": [],
    "رمان": [],
    "کلیات اسلام": [],
    "داستان کودک و نوجوانان": [],
    "جامعه‌شناسی": [],
    "داستان کوتاه": [],
}


subject_counts = {
    "مدیریت و کسب و کار": 0,
    "رمان": 0,
    "کلیات اسلام": 0,
    "داستان کودک و نوجوانان": 0,
    "جامعه‌شناسی": 0,
    "داستان کوتاه": 0,
    "کل": 0
}

# counting number of books in different categories
subject_counts["مدیریت و کسب و کار"] = train_df['categories'].value_counts()[
    "مدیریت و کسب و کار"]
subject_counts["رمان"] = train_df['categories'].value_counts()["رمان"]
subject_counts["کلیات اسلام"] = train_df['categories'].value_counts()[
    "کلیات اسلام"]
subject_counts["داستان کودک و نوجوانان"] = train_df['categories'].value_counts()[
    "داستان کودک و نوجوانان"]
subject_counts["جامعه‌شناسی"] = train_df['categories'].value_counts()[
    "جامعه‌شناسی"]
subject_counts["داستان کوتاه"] = train_df['categories'].value_counts()[
    "داستان کوتاه"]

sum = 0
for i in subject_counts.values():
    sum += i

subject_counts["کل"] = sum

subs_probs = []
for key in subject_counts:
    p = subject_counts[key] / subject_counts["کل"]
    subs_probs.append(p)

subs_probs.pop()


tr_categories = train_df["categories"].values.tolist()
result = transfer_data(train_df)

for i in range(len(tr_categories)):
    train[tr_categories[i]].append(result[i])

lst = [
    [],
    [],
    [],
    [],
    [],
    []
]
word_set = set()
k = 0
for key in train:
    for data in train[key]:
        words = data.split()
        for word in words:
            word_set.add(word)
        lst[k].append(words)
    k += 1

# stemming words of the list
stemmer = Stemmer()
word_set = list(word_set)
tmp_lst = []
for i in range(len(word_set)):
    w = stemmer.stem(word_set[i])
    tmp_lst.append(w)


# deleting stopwords from the set
word_set = tmp_lst
stopwords = np.array(stopwords_list())
words_num = len(word_set)
categories_num = 6
_list = list(word_set)
l = []
for i in range(len(_list)):
    if(_list[i] not in stopwords):
        l.append(_list[i])

l = np.array(l)
words_num = len(l)
bow = np.zeros((categories_num, words_num), dtype = int)
unique_words_dic = {}
for i in range(words_num):
    unique_words_dic[l[i]] = i


# making the bag of words
for i in range(len(lst)):
    for j in range(len(lst[i])):
        for k in range(len(lst[i][j])):
            if lst[i][j][k] in unique_words_dic:
                bow[i][unique_words_dic[lst[i][j][k]]] += 1


test = []
tes_categories = test_df["categories"].values.tolist()
tes_categories = np.array(tes_categories)
# mapping the category indexes
categories_map = []
res = transfer_data(test_df)
res = np.array(res)
for i in range(len(tes_categories)):
    new = res[i].split()
    match tes_categories[i]:
        case "مدیریت و کسب و کار":
            test.append(new)
            categories_map.append(0)
        case "رمان":
            test.append(new)
            categories_map.append(1)
        case "کلیات اسلام":
            test.append(new)
            categories_map.append(2)
        case "داستان کودک و نوجوانان":
            test.append(new)
            categories_map.append(3)
        case "جامعه‌شناسی":
            test.append(new)
            categories_map.append(4)
        case "داستان کوتاه":
            test.append(new)
            categories_map.append(5)

categories_map = np.array(categories_map)

correct = 0
all = 0

subject_sums = []
for i in range(6):
    subject_sums.append(np.sum(bow, axis = 1)[i])
subject_sums = np.array(subject_sums)

# calculating the probabilities and precision
for i in range(len(test)):
    probs = []
    for subject in range(6):
        log_sums = log1p(subs_probs[subject] * normalizer)
        for j in range(len(test[i])):
            w = test[i][j]
            if (w in unique_words_dic) and (bow[subject][unique_words_dic[w]] != 0):
                prob = (bow[subject][unique_words_dic[w]]) / subject_sums[subject]
                log_sums += log1p(prob * normalizer)
            else:
                log_sums = 0
                break
        probs.append(log_sums)
    if categories_map[i] == probs.index(max(probs)):
        correct += 1
    all += 1


ans = float(correct / all)
print ("{:.2%}".format(ans))
        