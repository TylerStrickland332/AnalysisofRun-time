# AnalysisofRun-time
Analysis of run-time and memory for data structures
This upload is of a series of projects I created.
The goal of these projects were to evaluate the run-time of three different data structures: vectors, data trees, and hash tables
Once the run-time of these different approaches were evaluated for sorting a list of courses I was to choose whichw was the most effective
Once the most effective was chosen I programmed an algorith that allows a user to upload any file they would like, use it and it's contents (assumably courses) to be put into the hash table
This program can also search for a specfific course using the course ID or list all of the courses alphanumerically
I apporached this project not knowing what any of these data structures were, but after learning how each worked and how they used their own seperate algorithms to search for a specific ID it was easier to identify which was the most effective
The hash table is the most effective because it can sort the objects into multiple buckets, and based on the input of the search can make an inferred guess on where to begin it's search. It then searches the whole bucket and goes on until it finds it or the bucket is fully searched and goes to the next. If it lands on an empty bucket or has searched them all it returns null. This method is most effective because it can usually find the class within the first few buckets. Compared to a data tree, if I were to search for the bottom-most ID it would have to go down the whole tree comparing values. As for a vector it simply searches one by one. So it's generally faster on more occurrences than the other two methods
Before this project I only knew vectors/arrays as data tables. I think when there's a large amount of data to search having these extra options will be useful, since each offers their own advantage
