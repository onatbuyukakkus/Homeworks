def is_Terminal(tree):
    if len(tree)<4:
        return True
    if type(tree)==str:
        return True
    else:
        return False

def adding_Zeros(tree):
    for i in range(len(tree)):
        if is_Terminal(tree[i]) == True:
                if type(tree[i]) == str:
                    tree[tree.index(tree[i])] = [tree[i]] + [0] + [0]
                elif type(tree[i]) == list:
                        if len(tree[i]) == 2:
                            if tree[i][1] >= 1:
                                tree[tree.index(tree[i])] = tree[i] + [0]
                            elif tree[i][1] <= -1:
                                tree[tree.index(tree[i])] = [tree[i][0]] + [0] + [tree[i][1]]
        else:
            adding_Zeros(tree[i])
    return tree

def complete_Tree(tree):
    root=tree[0]
    upper_Left=tree[1]
    lower_Left=tree[2]
    lower_Right=tree[3]
    upper_Right=tree[4]

    if is_Terminal(upper_Left) == False:
        if is_Terminal(lower_Left) == True:
            if upper_Left[0][1] > 0:
                lower_Left[1] = upper_Left[0][1]
            elif lower_Left[1] > 0:
                upper_Left[0][1] = lower_Left[1]

    if is_Terminal(lower_Left) == False:
        if is_Terminal(upper_Left) == False:
            if lower_Left[0][1] > 0:
                upper_Left[0][1] = lower_Left[0][1]
            elif upper_Left[0][1] > 0:
                lower_Left[0][1] = upper_Left[0][1]

    if is_Terminal(lower_Left) == False:
        if is_Terminal(upper_Left) == True:
            if lower_Left[0][1] > 0:
                upper_Left[1] = lower_Left[0][1]
            elif upper_Left[1] > 0:
                lower_Left[0][1] = upper_Left[1]

    if is_Terminal(upper_Right) == True:
        if is_Terminal(lower_Right) == True:
            if upper_Right[1] > 0:
                lower_Right[1] = upper_Right[1]
            elif lower_Right[1] > 0:
                upper_Right[1] = lower_Right[1]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(upper_Right) == True:
            if lower_Right[0][1] > 0:
                upper_Right[1] = lower_Right[0][1]
            elif upper_Right[1] > 0:
                lower_Right[0][1] = upper_Right[1]

    if is_Terminal(upper_Right) == False:
        if is_Terminal(lower_Right) == False:
            if upper_Right[0][1] > 0:
                lower_Right[0][1] = upper_Right[0][1]
            elif lower_Right[0][1] > 0:
                upper_Right[0][1] = lower_Right[0][1]

    if is_Terminal(lower_Left) == True:
        if is_Terminal(upper_Left) == True:
            if lower_Left[1] > 0:
                upper_Left[1] = lower_Left[1]
            elif upper_Left[1] > 0:
                lower_Left[1] = upper_Left[1]

    if is_Terminal(upper_Right) == False:
        if is_Terminal(lower_Right) == True:
            if upper_Right[0][1] > 0:
                lower_Right[1] = upper_Right[0][1]
            elif lower_Right[1] > 0:
                upper_Right[0][1] = lower_Right[1]

    if is_Terminal(upper_Left) == False:
        if is_Terminal(upper_Right) == True:
            if upper_Left[0][2] < 0:
                upper_Right[2] = upper_Left[0][2]
            elif upper_Right[2] < 0:
                upper_Left[0][2] = upper_Right[2]

    if is_Terminal(upper_Right) == False:
        if is_Terminal(upper_Left) == False:
            if upper_Right[0][2] < 0:
                upper_Left[0][2] = upper_Right[0][2]
            elif upper_Left[0][2] < 0:
                upper_Right[0][2] = upper_Left[0][2]

    if is_Terminal(upper_Right) == False:
        if is_Terminal(upper_Left) == True:
            if upper_Right[0][2] < 0:
                upper_Left[2] = upper_Right[0][2]
            elif upper_Left[2] < 0:
                upper_Right[0][2] = upper_Left[2]

    if is_Terminal(lower_Right) == True:
        if is_Terminal(lower_Left) == True:
            if lower_Right[2] < 0:
                lower_Left[2] = lower_Right[2]
            elif lower_Left[2] < 0 :
                lower_Right[2] = lower_Left[2]

    if is_Terminal(lower_Left) == False:
        if is_Terminal(lower_Right) == True:
            if lower_Left[0][2] < 0:
                lower_Right[2] = lower_Left[0][2]
            elif lower_Right[2] < 0:
                lower_Left[0][2] = lower_Right[2]

    if is_Terminal(lower_Left) == False:
        if is_Terminal(lower_Right) == False:
            if lower_Left[0][2] < 0:
                lower_Right[0][2] = lower_Left[0][2]
            elif lower_Right[0][2] < 0:
                lower_Left[0][2] = lower_Right[0][2]

    if is_Terminal(upper_Right) == True:
        if is_Terminal(upper_Left) == True:
            if upper_Right[2] < 0:
                upper_Left[2] = upper_Right[2]
            elif upper_Left[2] < 0 :
                upper_Right[2] = upper_Left[2]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(lower_Left) == True:
            if lower_Right[0][2] < 0:
                lower_Left[2] = lower_Right[0][2]
            elif lower_Left[2] < 0:
                lower_Right[0][2] = lower_Left[2]

    if is_Terminal(upper_Right) == False:
        if is_Terminal(upper_Left) == False:
            if upper_Right[0][2] < 0:
                upper_Left[0][2] = upper_Right[0][2]
            elif upper_Left[0][2] < 0:
                upper_Right[0][2] = upper_Left[0][2]


    if is_Terminal(lower_Left) == False:
        if is_Terminal(lower_Right) == False:
            if lower_Left[0][2] < 0:
                lower_Right[0][2] = lower_Left[0][2]
            elif lower_Right[0][2] < 0:
                lower_Left[0][2] = lower_Right[0][2]

    if is_Terminal(lower_Right) == True:
        if is_Terminal(upper_Left) == False:
            if lower_Right[1] > 0:
                if upper_Left[0][1] > 0:
                    root[1] = lower_Right[1] + upper_Left[0][1]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(upper_Left) == True:
            if lower_Right[0][1] > 0:
                if upper_Left[1] > 0:
                    root[1] = lower_Right[0][1] + upper_Left[1]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(upper_Left) == False:
            if lower_Right[0][1] > 0:
                if upper_Left[0][1] > 0:
                    root[1] = lower_Right[0][1] + upper_Left[0][1]

    if is_Terminal(lower_Right) == True:
        if is_Terminal(upper_Left) == True:
            if lower_Right[1] > 0:
                if upper_Left[1] > 0:
                    root[1] = lower_Right[1] + upper_Left[1]

    if is_Terminal(lower_Right) == True:
        if is_Terminal(upper_Left) == True:
            if lower_Right[2] < 0:
                if upper_Left[2] < 0:
                    root[2] = lower_Right[2] + upper_Left[2]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(upper_Left) == True:
            if lower_Right[0][2] < 0:
                if upper_Left[2] < 0:
                    root[2] = lower_Right[0][2] + upper_Left[2]

    if is_Terminal(lower_Right) == True:
        if is_Terminal(upper_Left) == False:
            if lower_Right[2] < 0:
                if upper_Left[0][2] < 0:
                    root[2] = lower_Right[2] + upper_Left[0][2]

    if is_Terminal(lower_Right) == False:
        if is_Terminal(upper_Left) == False:
            if lower_Right[0][2] < 0:
                if upper_Left[0][2] < 0:
                    root[2] = lower_Right[0][2] + upper_Left[0][2]
    return tree

def complete_Tree_Backwards(tree):
    root=tree[0]
    upper_Left=tree[1]
    lower_Left=tree[2]
    lower_Right=tree[3]
    upper_Right=tree[4]

    if root[1] != 0:
        if is_Terminal(lower_Right) == False:
            if is_Terminal(upper_Left) == False:
                if lower_Right[0][1] == 0:
                    lower_Right[0][1] = root[1] - upper_Left[0][1]
                elif upper_Left[0][1] == 0:
                    upper_Left[0][1] = root[1] - lower_Right[0][1]

        if is_Terminal(lower_Left) == False:
            if is_Terminal(upper_Right) == True:
                if lower_Left[0][1] == 0:
                    lower_Left[0][1] = root[1] - upper_Right[1]
                elif upper_Right[1] == 0:
                    upper_Right[1] = root[1] - lower_Left[0][1]

        if is_Terminal(upper_Left) == False:
            if is_Terminal(lower_Right) == True:
                if upper_Left[0][1] == 0:
                    upper_Left[0][1] = root[1] - lower_Right[1]
                elif lower_Right[1] == 0:
                    lower_Right[1] = root[1] - upper_Left[0][1]

        if is_Terminal(lower_Right) == False:
            if is_Terminal(upper_Left) == True:
                if lower_Right[0][1] == 0:
                    lower_Right[0][1] = root[1] - upper_Left[1]
                elif upper_Left[1] == 0:
                    upper_Left[1] = root[1] - lower_Right[0][1]

        if is_Terminal(upper_Right) == False:
            if is_Terminal(lower_Left) == True:
                if upper_Right[0][1] == 0:
                    upper_Right[0][1] = root[1] - lower_Left[1]
                elif lower_Left[1] == 0:
                    lower_Left[1] = root[1] - upper_Right[0][1]

        if is_Terminal(upper_Right) == False:
            if is_Terminal(lower_Left) == False:
                if upper_Right[0][1] == 0:
                    upper_Right[0][1] = root[1] - lower_Left[0][1]
                elif lower_Left[0][1] == 0:
                    lower_Left[0][1] = root[1] - upper_Right[0][1]

        if is_Terminal(lower_Right) == True:
            if is_Terminal(upper_Left) == True:
                if lower_Right[1] == 0:
                    lower_Right[1] = root[1] - upper_Left[1]
                elif upper_Left[1] == 0:
                    upper_Left[1] = root[1] - lower_Right[1]

        if is_Terminal(upper_Right) == True:
            if is_Terminal(lower_Left) == True:
                if upper_Right[1] == 0:
                    upper_Right[1] = root[1] - lower_Left[1]
                elif lower_Left[1] == 0:
                    lower_Left[1] = root[1] - upper_Right[1]

    if root[2] != 0:
        if is_Terminal(lower_Right) == False:
            if is_Terminal(upper_Left) == False:
                if lower_Right[0][2] == 0:
                    lower_Right[0][2] = root[2] - upper_Left[0][2]
                elif upper_Left[0][2] == 0:
                    upper_Left[0][2] = root[2] - lower_Right[0][2]

        if is_Terminal(lower_Left) == False:
            if is_Terminal(upper_Right) == True:
                if lower_Left[0][2] == 0:
                    lower_Left[0][2] = root[2] - upper_Right[2]
                elif upper_Right[2] == 0:
                    upper_Right[2] = root[2] - lower_Left[0][2]

        if is_Terminal(upper_Left) == False:
            if is_Terminal(lower_Right) == True:
                if upper_Left[0][2] == 0:
                    upper_Left[0][2] = root[2] - lower_Right[2]
                elif lower_Right[2] == 0:
                    lower_Right[2] = root[2] - upper_Left[0][2]

        if is_Terminal(lower_Right) == False:
            if is_Terminal(upper_Left) == True:
                if lower_Right[0][2] == 0:
                    lower_Right[0][2] = root[2] - upper_Left[2]
                elif upper_Left[2] == 0:
                    upper_Left[2] = root[2] - lower_Right[0][2]

        if is_Terminal(upper_Right) == False:
            if is_Terminal(lower_Left) == True:
                if upper_Right[0][2] == 0:
                    upper_Right[0][2] = root[2] - lower_Left[2]
                elif lower_Left[2] == 0:
                    lower_Left[2] = root[2] - upper_Right[0][2]

        if is_Terminal(upper_Right) == False:
            if is_Terminal(lower_Left) == False:
                if upper_Right[0][2] == 0:
                    upper_Right[0][2] = root[2] - lower_Left[0][2]
                elif lower_Left[0][2] == 0:
                    lower_Left[0][2] = root[2] - upper_Right[0][2]

        if is_Terminal(lower_Right) == True:
            if is_Terminal(upper_Left) == True:
                if lower_Right[2] == 0:
                    lower_Right[2] = root[2] - upper_Left[2]
                elif upper_Left[2] == 0:
                    upper_Left[2] = root[2] - lower_Right[2]

        if is_Terminal(upper_Right) == True:
            if is_Terminal(lower_Left) == True:
                if upper_Right[2] == 0:
                    upper_Right[2] = root[2] - lower_Left[2]
                elif lower_Left[2] == 0:
                    lower_Left[2] = root[2] - upper_Right[2]
    return tree

def iteration(tree):
    empty_List = []
    if len(tree) == 5:
        complete_Tree(tree)
    for i in range(len(tree)):
        if is_Terminal(tree[i]) == False:
            complete_Tree(tree)
            iteration(tree[i])
    empty_List.extend(complete_Tree(tree))
    return empty_List

def iteration_Backwards(tree):
    data1 = []
    for i in range(len(tree)):
        if is_Terminal(tree[i]) == False:
            complete_Tree_Backwards(tree)
            iteration_Backwards(tree[i])
    data1.extend(complete_Tree_Backwards(tree))
    return data1

def listing_Tree(tree):
    global lst
    for i in range(len(tree)):
        if type(tree[i][0]) == str:
            lst.append(tree[i])
        else:
            listing_Tree(tree[i])
    return lst

def make_List_Positive(lst):
    for i in range(len(lst)):
        lst[i][2] = abs(lst[i][2])
    return lst

def solveqtree(tree):
    global lst
    lst = []
    return make_List_Positive(listing_Tree(iteration_Backwards(iteration(adding_Zeros(tree)))))

print solveqtree()