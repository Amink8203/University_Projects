from collections import deque

class Hamsayeh:
    def __init__(self,pos,weight):
        self.pos = pos
        self.weight = weight

def hashing(possition_roww,possition_coll):
    return ((possition_roww-1)*mm + possition_coll)

def un_hashing(index_of_hash):
    index_col = index_of_hash % mm
    index_row = 0
    flag1 = True
    if index_col != 0 and flag1:
        index_row = ((index_of_hash // mm ) + 1 ) 
    elif index_col == 0:
        index_col = (mm * 1)
        index_row = (index_of_hash // mm)
    return index_col, index_row

internal = map(int,input().split())
internal = list(internal)
mm = internal[0]
nn = internal[1]
k = internal[2]
is_valid = True
num_of_lights = k
bright_places = dict()
new_m = mm + 1
col_bright_places = []
for j in range(new_m):
    col_bright_places.append(list())
can_use = True
new_n = nn + 1
row_bright_places = []
for j in range(new_n):
    row_bright_places.append(list())

last_place_seen = 0
i = 0
while (i < num_of_lights):
    internal = map(int,input().split())
    internal = list(internal)
    possition_col = internal[0]
    possition_row = internal[1]
    if not(possition_col == mm and possition_row == nn):
        bright_places[hashing(possition_row,possition_col)] = []
        col_bright_places[possition_col].append(hashing(possition_row,possition_col))
        row_bright_places[possition_row].append(hashing(possition_row,possition_col))  
    else:
        last_place_seen = 1
    i = i + 1

be_end = True
bright_places[hashing(nn,mm)] = []
col_bright_places[mm].append(hashing(nn,mm))
row_bright_places[nn].append(hashing(nn,mm))

level_of_node = {}
for table_element in bright_places:
    level_of_node[table_element] = float('inf')
    if not(table_element != hashing(nn,mm)):
        pass
    else:
        hamsaye_ha = []
        in_col = table_element % mm
        in_row = 0
        flag1 = True
        if in_col != 0 and flag1:
            in_row = ((table_element // mm ) + 1 ) 
        elif in_col == 0:
            in_col = (mm * 1)
            in_row = (table_element // mm)

        for i in range(in_col-2, in_col+3):
            if not(i < 1 or i > mm):
                for in_place in col_bright_places[i]:
                    col_element , row_element = un_hashing(in_place)
                    if not(in_place == hashing(nn,mm) and last_place_seen == 0):
                        if (in_place == table_element - mm or in_place == table_element + mm) and is_valid:
                            hamsaye_ha.append(Hamsayeh(in_place,0))
                        elif ((in_col != mm and in_place == table_element + 1) or (in_col != 1 and in_place == table_element -1)) and is_valid:
                            hamsaye_ha.append(Hamsayeh(in_place,0))
                        elif (col_element >= in_col-2 and col_element <= in_col + 2 and row_element >= in_row-2 and row_element <= in_row - 2) and is_valid:
                            hamsaye_ha.append(Hamsayeh(in_place,1))
                        elif can_use:
                            hamsaye_ha.append(Hamsayeh(in_place,1))
                    elif can_use:
                        if (i >= in_col-1 and i <= in_col + 1 and is_valid):
                            hamsaye_ha.append(Hamsayeh(in_place,1))

        for i in range(in_row-2, in_row+3):
            if not(i < 1 or i > nn):
                for in_place in row_bright_places[i]:
                    col_element , row_element = un_hashing(in_place)
                    if not(in_place == mm * nn and last_place_seen == 0):
                        if (in_place == table_element - mm or in_place == table_element + mm) and is_valid:
                            pass
                        elif ((in_col != mm and in_place == table_element + 1) or (in_col != 1 and in_place == table_element -1)) and is_valid:
                            pass
                        elif is_valid and (col_element >= in_col-2 and col_element <= in_col + 2 and row_element >= in_row-2 and row_element <= in_row - 2):
                            pass
                        elif can_use:
                            hamsaye_ha.append(Hamsayeh(in_place,1))
                    elif can_use:
                        if (i >= in_row-1 and i <= in_row + 1 and is_valid):
                            if not(col_element >= in_col-1 and col_element <= in_col + 1 and row_element >= in_row-1 and row_element <= in_row - 1):
                                hamsaye_ha.append(Hamsayeh(in_place,1))
        
        bright_places[table_element] = hamsaye_ha

can_do = True
end_process = 0
level_of_node[1] = -1
saf = deque()
saf.append(Hamsayeh(1, -1))
result = 0*end_process
fault = -1
while saf:
    if ((end_process == 0) and can_do):
        element = saf.popleft()
    elif not(end_process == 0):
        break
    if not(element.pos == hashing(nn,mm)):
        for hams in bright_places[element.pos]:
            new_level = level_of_node[element.pos] + hams.weight
            if (hams.pos == hashing(nn,mm) and can_do): 
                    result = new_level
                    end_process = 1
            if not(end_process == 0):
                break
            if not(new_level >= level_of_node[hams.pos]):
                level_of_node[hams.pos] = new_level
                if (hams.weight != 0 and can_do):
                    saf.append(Hamsayeh(hams.pos, hams.weight))
                elif can_do:
                    saf.appendleft(Hamsayeh(hams.pos, hams.weight))
    elif be_end:    
        break

if (end_process == 0):
    print(fault)
elif can_do:
    if not(last_place_seen and (mm * (nn-1)) in col_bright_places[mm] and be_end):
        print(result + 1)
    else:
        print(result)

