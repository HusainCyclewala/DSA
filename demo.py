no_pr = 4


processes = []
for i in range(no_pr):
    process = int(input(f"Enter size of process {i+1}: "))
    processes.append(process)


memory = [100, 500, 200, 300, 600]



def first_fit(processes, memory):
    mem_filled = [False] * len(memory)

    memory_used = 0
    allocated = False
    print("\nFirst Fit")
    print("PNo.\tPSize\tBNo.\tBSize")
    for at_process, process in enumerate(processes):
        for at_memory, block in enumerate(memory):
            if process <= block and not mem_filled[at_memory]:
                memory_used += process
                mem_filled[at_memory] = True
                print(f"{at_process + 1}\t\t{process}\t\t{at_memory}\t\t{block}")
                # print(f"Memory wasted = {memory_wasted}")
                allocated = True
                break

        if not allocated:
            print(f"{at_process + 1}\t\t{process}\t\tNOT ALLOCATED")
           
        allocated = False
    print(f"Efficiency = {memory_used/sum(memory)*100}%")

def best_fit(processes, memory):
    total_memory = sum(memory)
    memory = [(ind, block) for ind, block in enumerate(memory)]
    memory.sort(key = lambda x: x[1])
   
    mem_filled = [False] * len(memory)

    memory_used = 0
    allocated = False
    print("\nBest Fit: ")
    print("PNo.\tPSize\tBNo.\tBSize")
    for at_process, process in enumerate(processes):
        for at_memory, (mem_index, block) in enumerate(memory):
            if process <= block and not mem_filled[at_memory]:
                memory_used += process
                mem_filled[at_memory] = True
                print(f"{at_process + 1}\t\t{process}\t\t{mem_index}\t\t{block}")
                # print(f"Memory wasted = {memory_wasted}")
                allocated = True
                break

        if not allocated:
            print(f"{at_process + 1}\t\t{process}\t\tNOT ALLOCATED")
           
        allocated = False
    print(f"Efficiency = {memory_used/total_memory*100}%")

def worst_fit(processes, memory):
    total_memory = sum(memory)
    memory = [(ind, block) for ind, block in enumerate(memory)]
    memory.sort(key = lambda x: x[1], reverse = True)
   
    mem_filled = [False] * len(memory)
    memory_used = 0
    allocated = False

    print("\nWorst Fit: ")
    print("PNo.\tPSize\tBNo.\tBSize")
    for at_process, process in enumerate(processes):
        for at_memory, (mem_index, block) in enumerate(memory):
            if process <= block and not mem_filled[at_memory]:
                memory_used += process
                mem_filled[at_memory] = True
                print(f"{at_process + 1}\t\t{process}\t\t{mem_index}\t\t{block}")
                # print(f"Memory wasted = {memory_wasted}")
                allocated = True
                break

        if not allocated:
            print(f"{at_process + 1}\t\t{process}\t\tNOT ALLOCATED")
           
        allocated = False
    print(f"Efficiency = {memory_used/total_memory*100}%")
first_fit(processes, memory)
best_fit(processes, memory)
worst_fit(processes, memory)
