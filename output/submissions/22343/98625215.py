import os, io, sys
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
print = sys.stdout.write


t = int(input())

for _ in range(t):
    a = input()
    b = input()
    suma = 0
    sumb = 0
    st = []
    weight = 0
    added = False
    for ch in a:
        if ch == '(':
            if not st:
                weight = 1
            else:
                weight *= 2
            st.append('(')
            added = False
        elif ch == ')':
            if st and st[-1] == '(':
                st.pop()
                if not added:
                    suma += weight
                    added = True
                weight //= 2
            else:
                break
    st.clear()
    st = []
    weight = 0
    added = False
    for ch in b:
        if ch == '(':
            if not st:
                weight = 1
            else:
                weight *= 2
            st.append('(')
            added = False
        elif ch == ')':
            if st and st[-1] == '(':
                st.pop()
                if not added:
                    sumb += weight
                    added = True
                weight //= 2
            else:
                break
    st.clear()

    if suma > sumb:
        print('>' + '\n')
    elif suma < sumb:
        print('<' + '\n')
    else:
        print('=' + '\n')
