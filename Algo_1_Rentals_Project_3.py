# Ekaterina Miakotina and Evan Wenzel

import heapq # importing heap method in order to use min-heap(priority queue)

def min_rentals(times):
    # input times should be sorted from the first indx(0)
    times.sort(key = lambda x: x[0])

    # created an empty list, called min-heap, to track the end times
    min_heap = []

    for start, end in times:
        # if the start time greater or equal to the first index of min-heap,
        if min_heap and start >= min_heap[0]:
            # we pop the end time from heap, meaning that we reuse the laptop
            heapq.heappop(min_heap)
        # otherwise, we push the end time to the min-heap
        heapq.heappush(min_heap, end)
    # we need to return the number of laptop used, => the length of the min-heap
    return len(min_heap)

# asks for user's input
times_input = input("Input: ")

# makes an input as a list of tuples
times = []
# # here we convert an input into the list of tuples
for element in times_input.split():
    # at each element we remove parenthesese
    element = element.strip("()")
    # we split it by ,
    start, end = element.split(",")
    # convert to tuple that contains integers
    times.append((int(start), int(end)))

# prints the output for the user
print("\nOutput: ", min_rentals(times))
