/*
https://www.interviewbit.com/problems/reverse-link-list-ii/


# Pretty simple, just count upto the mth node, save it in the head, save the prev node in c0,

# c0 will be the connect point 0, which will connect to the LHS of reversed LL, head will be the node

# from where we wanna reverse LL

# Continue counting upto the the nth node, save it as tail, save the next of curr node in c1

# c1 will be the connect point 1, which will connect to the RHS of reversed LL 

# Make the next of tail as NULL, pass head and tail to reverse function and reverse the LL,

# It will return the new head and new tail of the LL, connect new head and new tail with c0 and c1

# respectively and return the list
*/