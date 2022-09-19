# Programmer: Ethan Heckart
# Date: 2/2/22
# File: 1200PaperHomework1.py

#################################### PROBLEM 1 TRUTH TABLE #############################################
print('Problem 1 Truth Table')
hyps = ['not p', 'p or q', 'not p or r']
concl = 'q or r'

fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^4s}|{4:^5s}|{5:^6s}|{6:^5s}|"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^4d}|{4:^5d}|{5:^6d}|{6:^5d}|"
div = "---+---+---+----+-----+------+-----+"

print(fst.format('p','q','r','~p','pVq','~pVr','qVr'))
for p in range(2):
    for q in range(2):
        for r in range(2):
            print(div)
            print (fst2.format(p,q,r, eval(hyps[0]), eval(hyps[1]), eval(hyps[2]),eval(concl)))
print('')
#################################### PROBLEM 1 VERIFICATION #############################################
print('Problem 1 Verification')
def ls(p,q,r):
    return (p or q) and ((not p) or r)
def rs(p,q,r):
    return q or r

tautology = True
for p in range(2):
    for q in range(2):
        for r in range(2):
            if ls(p,q,r)==True and rs(p,q,r)==False:
                tautology = False

if tautology:
    print("This expression is a tautology")
else:
    print("This expression is not a tautology") 
print('')
#################################### PROBLEM 2 TRUTH TABLE #############################################
print('Problem 2 Truth Table')
hyps = ['q <= (not p)', 'p or q', 'q <= r']
concl = 'r'

fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^9s}|{4:^5s}|{5:^8s}|{6:^3s}|"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^9d}|{4:^5d}|{5:^8d}|{6:^3d}|"
div = "---+---+---+---------+-----+--------+---+"

print(fst.format('p', 'q', 'r', 'q -> ~p', 'pVq', 'q -> r', 'r'))
for p in range(2):
    for q in range(2):
        for r in range(2):
            print(div)
            print(fst2.format(p,q,r, eval(hyps[0]), eval(hyps[1]), eval(hyps[2]), eval(concl)))
print('')
#################################### PROBLEM 2 VERIFICATION #############################################
print('Problem 2 Verification')
def prem1(p,q,r):
    return q <= (not p)
def prem2(p,q,r):
    return p or q
def prem3(p,q,r):
    return q <= r
def conclusion(p,q,r):
    return r

valid = True
for p in range(2):
    for q in range(2):
        for r in range(2):
            if prem1(p,q,r)==True and prem2(p,q,r)==True and prem3(p,q,r)==True and conclusion(p,q,r)==False:
                valid = False

if valid == True:
    print('This argument form is valid.')
if valid == False:
    print('This argument form is invalid.')
print('')
#################################### PROBLEM 3 TRUTH TABLE #############################################
print('Problem 3 Truth Table')
hyps = ['g or y', '(g and y) <= n', 'y and (not n)']
concl = 'not g'

fst = "{0:^3s}|{1:^3s}|{2:^3s}|{3:^5s}|{4:^10s}|{5:^6s}|{6:^3s}|"
fst2 = "{0:^3d}|{1:^3d}|{2:^3d}|{3:^5d}|{4:^10d}|{5:^6d}|{6:^3d}|"
div = "---+---+---+-----+----------+------+---+"

print(fst.format('g', 'y', 'n', 'gVy', 'g^y -> n', 'y^~n', '~g'))
for g in range(2):
    for y in range(2):
        for n in range(2):
            print(div)
            print(fst2.format(g,y,n, eval(hyps[0]), eval(hyps[1]), eval(hyps[2]), eval(concl)))
print('')
#################################### PROBLEM 3 TRUTH TABLE #############################################
print('Problem 3 Verification')
def prem1(g,y,n):
    return g or y
def prem2(g,y,n):
    return (g and y) <= n
def prem3(g,y,n):
    return y and (not n)
def conclusion(g,y,n):
    return not g

valid = True
for g in range(2):
    for y in range(2):
        for n in range(2):
            if prem1(g,y,n)==True and prem2(g,y,n)==True and prem3(g,y,n)==True and conclusion(g,y,n)==False:
                valid = False

if valid == True:
    print('This argument form is valid.')
else:
    print('This argument form is invalid.')