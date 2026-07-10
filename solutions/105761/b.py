nums = list(map(int, input().split()))

while (nums[len(nums)-1] != nums[1] or nums[len(nums)-2] != nums[0]) or len(nums) <= 2:
    newNums = nums[len(nums)-1] + nums[len(nums)-2]
    nums.append(int(str(newNums)[len(str(newNums))-1]))

print(len(nums))
