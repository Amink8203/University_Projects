inp = input()
letter_count = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
bitmap_dict = {0 : 1}
bitmap = 0
count = 0
for letter in inp:
    let_ind = ord(letter) - ord("a")
    letter_count[let_ind] += 1
    bitmap = bitmap ^ (1 << let_ind)

    for num in range(10):
        new_bitmap = bitmap ^ (1 << num)
        if new_bitmap in bitmap_dict:
            count += bitmap_dict[new_bitmap]
    
    if bitmap in bitmap_dict:
        count += bitmap_dict[bitmap]
        bitmap_dict[bitmap] += 1
    else:
        bitmap_dict[bitmap] = 1

print(count)