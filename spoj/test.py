while True:
    try:
        s=int(input())
    except EOFError:
        break
    if s==0:
        print(0)
    elif s==1:
        print(1)
    else:
        print(2*s-2)