import sys

t = int(sys.stdin.readline().strip())

for _ in range(t):
    a, b = sys.stdin.readline().split()

    suma = 0
    sumb = 0

    # a 처리
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

    # b 처리
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
