res = 0

with open("input.txt", 'r') as file:
    line = file.readline()
    while line != '':
        nums = []
        for a in line.split(','):
            for b in a.split('-'):
                nums.append(int(b))

        if (nums[0] <= nums[2] and nums[1] >= nums[3]) or (nums[0] >= nums[2] and nums[1] <= nums[3]):
            res += 1
        line = file.readline()

print(res)