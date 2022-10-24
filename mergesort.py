from operator import le
from typing import List

def merge_sort(data) -> None:
  # Write code here
  if len(data)>1:
    mid = (len(data))//2
    l_arr = data[:mid]
    r_arr = data[mid:]

    merge_sort(l_arr)
    merge_sort(r_arr)

    i = 0
    j = 0 
    k = 0

    while i < len(l_arr) and j < len(r_arr):
      if l_arr[i] < r_arr[j]:
        data[k] = l_arr[i]
        i+=1
      else:
        data[k] = r_arr[j]
        j+=1
      k+=1
    
    while i < len(l_arr):
      data[k] = l_arr[i]
      i+=1
      k+=1
    while j < len(r_arr):
      data[k] = r_arr[j]
      j+=1
      k+=1

    return data

# Do not change the following code
input_data = input()
data = []
for item in input_data.split(', '):
  if item.isnumeric():
    data.append(int(item))
  elif item.lstrip("-").isnumeric():
    data.append(int(item))
merge_sort(data)
print(data)
