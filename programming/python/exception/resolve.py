

def check_value(n):
    try:
        x =  n / n
    except Exception as err:
        raise err
    else:
        print("the result is ", x)
    finally:
        print("input was ", n)

    

check_value(1)
check_value(0)