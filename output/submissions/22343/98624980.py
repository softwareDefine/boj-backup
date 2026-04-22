import sys

t = int(sys.stdin.readline().strip())

for _ in range(t):
    a = sys.stdin.readline().strip()
    b = sys.stdin.readline().strip()
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
        print('>')
    elif suma < sumb:
        print('<')
    else:
        print('=')
