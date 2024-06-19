# https://leetcode.com/problems/two-sum/


def twoSum(nums, target):
    result = []
    for i in nums:
        for j in range(len(nums) - 1):
            izq = j
            der = j + 1
            if nums[izq] + nums[der] == target:
                return [izq, der]
    return []


def main():
    nums = []
    array = input("Insert numbers of list, separated by a space: ")
    x = array.split()
    for i in x:
        try:
            i = int(i)
            nums.append(i)
        except:
            print("this is not a number")
    target = int(input("insert target: "))
    twoSum(nums, target)


main()
