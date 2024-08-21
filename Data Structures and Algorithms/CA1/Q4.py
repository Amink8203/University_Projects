def check(s):
    n = len(s)
    correct_sum = False
    temp = []
    i = 1
    prev_i = i
    num1 = 0
    num2 = 0
    num3 = 0
    start = 0
    correct_num_2 = 0
    correct_num_3 = 0
    lst = []
    nums = 0
    while(i <= n):
        if start != 0:
            new_str_num = s[start:i]
            if new_str_num[0] == '0' and len(new_str_num) > 1:
                i = prev_i
                start = 0
                nums = 0
                continue
            new_num = int(new_str_num)
            temp.clear()
            temp.append(len(str(correct_num_2)))
            temp.append(len(str(correct_num_3)))
            if new_num == correct_num_2 + correct_num_3:
                correct_num_2 = correct_num_3
                correct_num_3 = new_num
                start = i
                i = start + 1
                nums += 1
                continue
            elif i == n or len(new_str_num) > max(temp) + 1:
                i = prev_i
                start = 0
                nums = 0
                continue
            else:
                i += 1
                continue

        num1_str = s[start:i]
        for j in range(i + 1, n):
            num2_str = s[i:j]
            if num2_str[0] == '0' and len(num2_str) > 1:
                break
            for k in range(j + 1, n + 1):
                num3_str = s[j:k]
                if num3_str[0] == '0' and len(num3_str) > 1:
                    break
                temp.clear()
                temp.append(len(num1_str))
                temp.append(len(num2_str))
                if len(num3_str) > max(temp) + 1:
                    break
                num1 = int(num1_str)
                num2 = int(num2_str)
                num3 = int(num3_str)
                if num1 + num2 == num3:
                    if len(lst) != 0:
                        if lst[0] == j and lst[1] == k:
                            lst.clear()
                            break
                    lst.append(j)
                    lst.append(k)
                    nums = 0
                    correct_num_2 = num2
                    correct_num_3 = num3
                    correct_sum = True
                    start = k
                    prev_i = i
                    i = start
                    nums = 3
                    break

            if correct_sum:
                correct_sum = False
                break
        i += 1

    if nums >= 1:
        return "YES"
    else:
        return "NO"

inp = input()

result = check(inp)
print(result)
