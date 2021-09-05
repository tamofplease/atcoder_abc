A, B, K = map(int, input().split())



    

def get_prime(cur_n: int) -> int:
    if cur_n == 1:
        return 1
    else:
       return get_prime(cur_n-1) * cur_n

all_num = get_prime(A + B) // (get_prime(A) * get_prime(B))


# 2, 2, 6, 4 b
# 2, 1, 3, 1 a
# 1, 1, 2, 1 a
# 0, 1, 1, 0 b
def rep_solve(rest_a: int, rest_b: int, all_comb: int, cur_n: int) -> str:
    if rest_a == 0:
        return rest_b * 'b'
    elif rest_b == 0:
        return rest_a * 'a'
    else:
        
        
print(rep_solve(A, B, all_num, K))

