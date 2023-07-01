# MetroParis system report

Team members: Yutao Chen, Fuming Fu, Ke Sun, Nana Pan

From 19/06/2023-30/06/2023

# abstract:

MetroParis system is one of the Data Structure projects in design class, achieving to find the shortestPath in the metropolitan in Paris, the project is based on the C++ data structure, and using Python library to visualize result in HTML, aiming to create a user friendly, real-time respond,  with great design UI web demo application. since the limit time for two weeks, we have established the well-structure class, basic function , and demo UI framework for project, the report will shows these results as follow, to declare our understanding and analysis for our project , and also represent demonstrate how we interactive with our demo program, additionally giving the content processing debug and figuration, and finally make conclusion.This report is also as [README.md](http://README.md) for our repository.

# Demonstrate:

1. open the google colab  and input the visualize.ipynb
    
    ![螢幕截圖 2023-07-01 18.25.53.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.25.53.png)
    
2. the run the cell one by one to import the library and clone the MetroParis project

```
%cd /content/MetroParis
!git pull

#this cell is use for pull the updates after commit MetroParis project into google colab , no need to run at first

#The hide cell of below two is test function for visualizing , you don`t need to run these two.
```

1. run the first python cell
    
    ![螢幕截圖 2023-07-01 18.34.25.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.34.25.png)
    

you will see the output shows the windows for user, first choose a source station from metro line, once you chose the line, then select the name of station.

you will receive some **recommend Station** based on what you chose, click save to set as destination, if you don`t want to chose from recommend, click turn back and set destination station as beginning way.

for example i chose **‘Château de Vincennes’** in metro 1 as source station, and i don`t want to chose recommend station from list, click ‘back’, and chose **‘Porte de Bagnolet’** in metro 3 as destination station.

![螢幕截圖 2023-07-01 18.42.38.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.42.38.png)

![螢幕截圖 2023-07-01 18.44.45.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.44.45.png)

![螢幕截圖 2023-07-01 18.45.57.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.45.57.png)

1. run the second python cell

![螢幕截圖 2023-07-01 18.46.44.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.46.44.png)

![螢幕截圖 2023-07-01 18.48.27.png](MetroParis%20system%20report%202b2b799ef48c4a6e9dfee523d4f1a8f3/%25E8%259E%25A2%25E5%25B9%2595%25E6%2588%25AA%25E5%259C%2596_2023-07-01_18.48.27.png)

the output will shows three metro line with **different color** based on **real metro Paris color**, so you maybe familiar with these metro line, then using zoom in , to focus on the station **highlight by the same color as metro line**, the meaning you cross the three metro line from source to destination station.

the final cell is use to updates the selected source and destination station info into our github project, since it use personal github account and clone project to updates, you may not be able to updates the station from google colab, due to we use python as Front-end program for visualize and C++ as a Back-end program for manage and operate Station and line data in metro system, it is also difficult to make these program efficiently running in limit project time, so we figure out use github updates the data between front and back.

# Introduction

### The project about data structure for current stage mainly compile with two parts

### The graph class:

`Staiton.h` ( Node and edge object class)

`LinkedList.h` ( template Cell<T> object class for list)
`StationLine.h` ( Linked-list object class )

`MetroNetwork.h` (adjacency matrix and list object class)

### and the graphic function:

`MetroData.h` ( read and write for adj matrix and list)

`ShortestPath.h` ( find shortest path for metro line)

**you could see our project UML diagram in** [**`here`**](https://mermaid.live/view#pako:eNqdVm1v2jAQ_iuRP20qrURLW0AIiZZ2q1QqNFA_TEiTFx_gNbEj22GlFf9957w6IWmlfYHcc-fz3XN3tt-JLxmQIfEDqvWU042i4Up4XiJ7T6j03q3seVwYj7P0Wxs2HGqjuNh4goZwjG5AziUuSTUnGzDW15Qa-uVriT0wV3pCT678LfNRYEbeLp5T6VAGecc2RZBpCFuqgP2KjBrZTceelrHy4SMLBtpwQQ2XIjVjMv4dgMe4NlTkazPQKLqDYMnzvC0zPo2oz83-mImAi8wOXg0okSp34BupRo3RjD2Bf7p1kU147AH-6pIsC9bpvc2CcrFFwoWLTLMcXWxZpFixLFly4UfM8KgqCL4Ae0TfbbW5hSAYLTHbLdCsr0640KDMxNzAhguB9BX75Jo7UfZMJKN7JcNj40zh2mqgyt_aPQvIFl3JvY3xAUnGvHbQpPwBfqy0q8Skv2PQpXP-1shA0ZclG3lLmoRGXcnO-lyYKr-pBjOpKzDHJnuEG4zT7OtokaOADwgQcEwAzkUU0H1Z-SZSsIWW5cQioiCUO8iisAV6Thr6YxpngGE8gfkr1UullUIajXD0Ot7nQ9Rg3zKAyWzhYsr-UB-EnzRAq5PWEI7czCieBq__G42CHSgNk5agstXobuxF0oAwnAZIs9s3eadRdtQcCNmNXHne4qVsS_2piT1sjiG7k7a1b9HdYKUBRB515X6wBa234INYS0tHE56SXtdMqjVxd5gj8eCD1lJVdl7Efh2lggb7N8ga0zWeBEGSpIvhBMkwBMGm94sCd79dmxsHL77rE2HP-nwccLAos5ze86As41_FDQ5gBcNtZvQ1Ize_fR3Xi61UBgd_Ts228L7mWFxH4axKHginp8kdbGXn1EfUajM0sSq1Fq0MtmNdx3PfZdoIukZWWQm8picdEoIKKWf40EmSWhGzBby-yRA_GaxpHJgVWYkDmtLYyMVe-GS4poGGDokjRg1kb6Maesc4Tl4BQiLOsieV_euQiIqfUuJCo2JIRDJ8J69keDHonw0Gg-veZb_X618Nupcdskf47Lx33r3u9s6v-hf9bv_60CFviYPu4R-88zA-)

# Source

The STIF provides the following data about the rail network:[**`here`**](https://data.iledefrance-mobilites.fr/explore/dataset/emplacement-des-gares-idf-data-generalisee/table/)

RATP metro system map: [**`here`**](https://www.ratp.fr/en/plans)

wiki Paris Métro:[**`here`**](https://www.wikiwand.com/en/Paris_M%C3%A9tro)

coordinator in 2d and 3d vector, `‘ Geo Point’` and `‘Geo Shape’`

unique ID, `‘codeunique’`

metro line, `‘res_com’` ( this value is for Station, Node class,  but in our  project we define the ‘unique metro line’ in edge class )

StartEnd station, `‘principal’`

# Purpose:

### list of specific goals in our project

create `Node` class, containing basic Initialize constructor, and get, display function, also the edge class

create `LinkedList` class, recommend initialize as template<Cell<T>> type for project custom class define, with basic LinkedList operation.

create `adjacency matrix and list` class, with operation for add and store, caring memory deallocation.

Design the **data format** and following create read and save function for our adjacency matrix and list.

create function to **get predecessors and successors** in adjacency matrix and list.

using **Dijkstra algorithm** to achieve find the **shortest path**, with suitable parameters ( source ID, destination ID, distance as default parameter, extra other parameters.)
using **display** library to show the line with shortest path.

# Design:

### In this session i will represent our figuration during the project

1. design data structure for Node and edge
in our project, as you see the UML diagram, we have few Node and edge object in these class

```markdown
#Station
'''
std::shared_ptr<Node> source;
std::shared_ptr<Node> destination;
'''

shared_ptr<Node> object give a smrat pointer for Node object, has some advantage from our project
Memory Management: it automatically ensures that the memory to which it points is released when it's no longer needed 
(when the last shared_ptr referencing the object is destroyed). it`s also fits our reqiurement for memory deallocation

Avoid Raw Pointers: This is very useful when debug the graph function, 
due to it will have many Node and edge operation in these process, making debug more effcient.

Thread Safety: the same as above

Shared Ownership: compare with unique_ptr, since the Node and edge object are more frequently using the any sitution, 
this is good at allowing multiple pointers to point to the same object
```

```markdown
'''
extern std::vector<std::shared_ptr<Node>> nodes;
extern std::vector<Edge> edges;
'''

the vector of Node and edge object ( also for std::shared_ptr<Node>), give a dynamic size arrays, 
which is every useful store an direct list of Node and edge object dynamically, 
also the .find() function is strightfoward to check the unique Node and edge object to avoid rebuilding.

'''
std::map<int, std::shared_ptr<Node>> nodes;
std::map<int, std::vector<std::shared_ptr<Edge>>> adjacencyList;
std::map<int, std::map<int, std::shared_ptr<Edge>>> adjacencyMatrix;
'''

The map's keys are the node identifiers (integers) and the values are vectors of shared pointers to Edge objects.
```

2. design for Linkedlist

```markdown
#StationLine.h
StationLine.h is implement by Linkedlist function, aiming to add specifc parameter and function for line object.

due to our project using python and c++ both to deal with the data, the data form is always as a list 
( for finding Shortest , DFS and BFS, they are all return as list form ), creating new method based on these graph function 
for our line object is needed and useful.

such as:
void saveToCSV(const std::string& filename) const;
we store all the list object from function turn into csv file and push into python to visualized, it`s for now a convinent idea.
```

1. design for adjacency matrix and list

```markdown
#MetroNetwork.h
The adjacency matrix and list is the code part for graph, also for this project ,since we have many function in this part,
based on our need, the adjacency matrix not only has basic graph function, 
but also:

'''
void analyzeNetwork();
void addPotentialStartEndStation(int id);
bool isPotentialStartEndStation(int id) const;
'''

since we see the 'principal' in data format, 
this is boolan value define whether the station is a Start/End Station for a metro line.
so at the network, we also use analyzeNetwork() to iterative the node in matrix and define the 'principal' of edge , 
which is useful when we need to read and use edge object to avoid double iterative increasing time complexity.
```

```markdown
struct EdgePtrComp {
        bool operator()(const std::shared_ptr<Edge>& lhs, const std::shared_ptr<Edge>& rhs) const {
            return *lhs < *rhs;
        }
    };

struct EdgePtrComp is originally use for set<std::shared_ptr<Edge>>, 
EdgePtrComp instead sorts shared_ptr<Edge> by the values they point to using operator< on those values. 
This assumes that operator< is overloaded for Edge objects.
std::set and std::multiset sort their elements using operator<. 
However, for shared_ptr, this would sort by the pointers’ addresses, not the values they point to.

so in this function
'''
std::set<std::shared_ptr<Edge>, EdgePtrComp> getAllEdges() const;
'''

The main advantage of std::set is that it ensures all elements are unique 
-- there would be no duplicate edges. Duplicate shared pointers would not be inserted.
The reason for sorting with EdgePtrComp is to make sure the Edges are sorted not by their pointer addresses 
but by the values they point to--ID(codeunique)
```

after figuring out these type of class, we have many chose to implement function depends on our require.

For example ,if we have to store a list of station, first based on the **list size**, we could chose `vector of shared_ptr<Node>` , `linkedlist (small size)` or the `set<std::shared_ptr<Node>(large size)`, and then we could decide whether the Station is listed as **order** (shortest path) using vector (dynamically operate size and also straightforward using `find()` check unique station, or **non-order**(custom recommend Station line) using linkedlist, are easy for read and store Node object by pointer, which is not strictly, but just shows how flexible we are using these in project.

## Brief code review:

From this part due to the content limit, i reduce this part since the basic logic for graph class and graph function is clear, we use more content for introducing the unique of this project from our progress.

# Explain:

### In these session , we mainly discuss about some aspect we are dive into for our project.

**Error handling:** Compare with other project, this project for current stage is also a small project , with limit code, but we have enough error handling method in our graph class and graph function, it is essential for us to review the code when debugging, and also avoid the Thread error.

**Time complexity:** it is also a import part we always look though when we design for graph class and function, as we discuss in design session, we figure out many way to fits the operating of object from what we need and make sure its efficiency, this is a good start from small project and make it become larger.

**Easy-reading:** it is also well-structure adventure for project team work, for every member could understand the current stage for project and self-dealing the detail for modify and implement first, it is efficient.  

# Issues:

### indeed, we have a lot of issues and goal due to limit of time and knowledge , we fail to achieve at the due.

1. **a more useful and powerful data format** 

Our data for current stage just store three metro line ,due to we have limit line for data clean, even if we use python, from official raw data , reading and writing a data format we need and debug the method of data clean, so we just import three metro line for demo test.

1. **a more flexible parameter for finding short path**

as our project parameter, we add the ‘capacity’ and ‘distance’ for shortest path parameter, but it are still static const value, we have no time to implement more actually use for real metro situation due to we only have one Dijkstra algorithm for finding, we could add more algorithm and considering more parameter based on the requirement from user, for example, the user want less transport from line to line, it may not be time optimize but it meets the user requirement.

1. **a more interaction UI with user for metro system**

UI will highlight the metro system project since it is very helpful from visualizing, not only for user but also exciting for developer , we could make a clear view of which part goes wrong directly from visual map.

1. **a better compatible environment with C++ and python**

since it is the first time we deal with the front and back end situation , also want more challenge and useful for our project, the current stage using google colab and git function is not efficient but it works first, we could find more and get knowledge of these area when becoming to a real developer for project.

## Debug:

There are tons of detail and small error during the implementation, we not introduce these in there also due to the content limit,  but i want to mentioned that it is benefit especially from the beginner when implement the project , deal with the error situation could extend the understand for our project and also for the future project.

# Division of Labor within the group

This report is written by the leader, Yutao Chen, create the rule for our labor in project , attribute the tasks depending on the logic and coding knowledge for each member, and then gathering these progress to leader, to improve,  modify and implement. 

here are basic division

| Name | design data and class | demo/test code | implement  | report | Data clean for C++ and python | Management(team daily route)  |
| --- | --- | --- | --- | --- | --- | --- |
| Yutao Chen | 60%( design parameter and class object, the data format from raw) | 10% | 50%(implement demo code into project based on design) | 50%(the project content of report) | 5%(design demo format) |  |
| Fuming Fu | 20% | 60%(most of tasks demo code) | 30%(visualizing test) | 10% | 20% (python) |  |
| Ke Sun | 10% | 20% | 10% | 10% | 55% ( metro line data) |  |
| Nana Pan | 10% | 10% | 10% | 30%(The rest part) | 20% | bouns point |

### here are some detail content for code labor:

- **Sun ke**: Responsible for defining and implementing metro lines and stations, data input, and storage.
- **Pan nana**: Handles data input functions, including reading and storing information about metro lines and stations.
- **Fu fuming**: Conducts research on shortest path planning, designs and implements the user interface, and provides appropriate outputs.
- **Chen yutao**: Develops route planning functionality, utilizes the shortest path algorithm to generate optimal routes. Addresses potential errors and exceptions, optimizes code performance.

# Daily work record

### here are some basic route we follow for each days

**Day 1:**

1. Discuss and introduce project objectives and requirements.
2. Assign roles and responsibilities, clarify tasks for each team member.
3. Discuss project framework and theme.

**Day 2:**

1. Conduct research and gather relevant resources to provide foundational knowledge for the project.
2. Determine goals and methods.
3. Collaborate and divide work among team members, with each member starting on their assigned tasks.

**Day 3-5:**

1. Independently work on respective tasks and complete assigned work.
2. Hold team meetings to report progress and engage in, share opinions, and provide support for the project.

Day Consolidate the individual contributions and create a preliminary course design plan. 2. Conduct project review to ensure compliance with project requirements.

**Day 8:**

1. Revise and improve the course design plan based on feedback and suggestions.
2. Provide feedback and suggestions to each other for improvement.

**Day 9:**

1. Finalize the course design plan and prepare for project presentation.
2. Deliver the final presentation and showcase the project achievements to the instructor.

# Review from each member:

here is each member written by themselves

### Nana Pan:

I felt extremely excited and fulfilled during the group project for course design. Through collaboration with team members, I gained a wealth of knowledge and skills. By working together to solve problems, dividing tasks, and brainstorming ideas, we successfully completed the entire project. This experience not only enhanced my communication and teamwork abilities but also made deeply appreciate the power of collective wisdom. Moreover, I learned how to organize my thoughts logically, refine proposals, and effectively manage my time, which made me more mature and confident. At the same time, I also discovered areas where I was lacking and made efforts to improve my skills. Overall, this group project has had a positive impact on my personal growth and development.

### Fuming Fu

In the first two days of the project, I constantly searched for information related to the project to learn. When encountering problems, I promptly communicated with team members to find solutions. Starting from the third day, I tried to use code to solve project tasks. Every day thereafter, I continuously refined the functionality of the code and solved any problems I encountered.

Through these two weeks of course design, I have the following reflections:

1. Combining practice with theory: The design of data structure courses often requires students to implement commonly used data structures, such as linked lists, stacks, queues, trees, etc. Through practical means, we can better understand the principles and operations of these data structures. At the same time, practice can also help us deepen our understanding and application of algorithms.
Exercise programming skills: In the design of data structure courses, we need to use programming languages to implement various data structures and related algorithms. This not only requires us to master the syntax and features of programming languages proficiently, but also requires us to have good programming habits and debugging skills. Through such practice, we can improve our programming skills and cultivate problem-solving abilities.

2. Cultivate abstract thinking: Data structure is the foundation of computer science, which can help us organize and manage data, and solve various practical problems. In course design, we need to abstract practical problems into appropriate data structures and design corresponding algorithms to solve them. This requires us to have good abstract thinking skills, be able to decompose and summarize problems, and find the optimal solution.

3. Developing teamwork skills: In some large-scale course design projects, students often need to form small groups to complete tasks. This design can cultivate our teamwork ability and learn to communicate and collaborate effectively with others. By collaborating with others, we can learn from each other, solve problems together, and improve the quality and efficiency of projects.

Difficulties: When programming code, errors often occur due to the lack of corresponding modules in the imported function library, and errors occur when processing data due to a lack of timely understanding of how to handle data blocks

Solution of Problems: Conduct corresponding problems to be addressed, consult relevant materials or learn videos, debug the code multiple times, and ultimately solve the corresponding problems

### Ke Sun

In completing this course project on drawing a subway map, I deeply realize the important role that data structures play in our daily lives and studies.

Data structures can effectively support access, modification, and operation of data. When writing programs, choosing an appropriate data structure is crucial for improving program performance and readability.

During algorithm implementation, we will encounter many challenges. For example, how to optimize algorithm efficiency, how to collect and store suitable and effective subway station information, and so on. These problems require us to apply what we have learned, acquire new knowledge from the internet, and constantly try and adjust until we find a solution that satisfies both requirements and efficiency.

In summary, this course project has made me deeply understand the importance of data structures. Through this project, I not only improved my programming skills but also gained a deeper understanding of graph theory. I believe that these knowledge and skills will have a positive impact on my future learning and work.

### **Yutao Chen**

thanks for pro.NEGZZA and my team member , this times it quite short for me from day and night implement, although there are a lot of improve for this project ,but it is a good beginning for our code and develop route, hope see you next time, happy vacation.
