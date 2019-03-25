import multiprocessing as mp

print("This machine has", mp.cpu_count(), "cores ")

def fat(x):
    if x == 0: return 1
    elif x == 1: return 1
    else: return x*fat(x-1)


pool = mp.Pool(processes=4)
results = [pool.apply(fat, args=(x,)) for x in range(0,100)]
print(results)