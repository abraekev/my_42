# Pseudo Code

### should the input handle long or int?

### initial code
```markdown
> Validate inputs
> Initiate stack a
> Check if stack a is sorted
    > if not sorted -> sort algorithm
        > check if 2 numbers
        > check if 3 numbers
        > else, use *turk algorithm*
```

### Turk Algorithm aka. sort_stacks() 34:10
```markdown
> push all nodes from a to b untill 3 are left in a.
> during each push to b, b is sorted in *Descending* order.

> push the first 2 a nodes without checking anything
> find the cheapest node to push.
    >   calc the target nodes for each node in a. target node =
        'closest smaller number to the a node', else its the max value in b.
    >   (# ops to bring node a on top) + (# ops to bring node a's target node on top)
        = push cost

```




1507