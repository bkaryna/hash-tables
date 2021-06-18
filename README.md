# Hash tables
The project contains implementation of basic operations (`insert`, `find`, `delete`) for hash tables. Collisions are resolved through chaining and open addressing (structures hashChain and hashOpen respectively). 

## Chain method
All elements corresponding to the same key are placed in one slot (vector). 
### Time complexity
Worst case: all elements end up in one vector. In this case, the hash table is basically an array. Time complexity for `find` is `Θ(number of elements)`. Operations `insert` and `delete` have a similar complexity.
Best case: provided that the hash function is good (all elements have the same probability of being placed into one of the vectors). Consequently, all vectors' sizes are equal to (number of elements)/(number of vectors), so the time complexity of `insert`, `find`, `delete` operations is `Θ(number of elements)/(number of vectors))`.

#### Number of elements vs. number of comparisons
<img width="869" alt="image" src="https://user-images.githubusercontent.com/61482996/122614086-45ca1a00-d086-11eb-8091-861b7988fc26.png">

#### Slot index vs number of elements in the slot
<img width="824" alt="image" src="https://user-images.githubusercontent.com/61482996/122614126-5b3f4400-d086-11eb-974e-353aa608611e.png">


## Oped addressing method
All elements occupy the hash table itself, which means that maximum capacity of such table is the its size. While performing an insertion, the hash table is being examined (or probed) until an empty slot is found. The probe sequence (a permutation of `{0,1,...,size-1}`) is generated for each key `k`, so that every position is evengly considered as a slot for a new key as the table fills up. Special values of `-1` and `-2` are used to mark empty or deleted slots.

### Time complexity
Finding an empty slot (auxiliary operation): Θ(number of elements)
`find`: `Θ(1/(1-load factor))` for the unsuccessful search and `Θ(1/(ln(load factor)) * (1/(1-load factor)) + 1/(load factor))` for a successful search.
`insert`: `Θ(1/(1-load factor))`;
`delete`: heavily depends on the implementation

#### Number of elements vs. number of comparisons
<img width="974" alt="image" src="https://user-images.githubusercontent.com/61482996/122613942-f5eb5300-d085-11eb-87de-4c21cb09fa7d.png">

#### © based on Introduction to Algorithms by Thomas H. Cormen, Charles E., Leiserson Ronald L., Rivest Clifford Stein
