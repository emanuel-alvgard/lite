# lite
Is a **general purpose programming language** that aims at being:
+ __Readable__
+ __Fast__
+ __Safe__
+ __Small__
+ __Independent__

Examples
------
**Assignment**
````
# single line comment

#/
multi line
comment
/#

var0: 1, 2, 3
var0: ++

# var0 = 2, 3, 4 
# all variables are arrays and assignments are looped by default.
````
**Keywords**
````
function test: none
  skip
  
primitive _bool:
  true, false
  
composite Vector2:
  x: f4
  y: f4
````
Features
------
+ Strong typing
+ High interoperability with C
+ Powerful looping
+ Deterministic scoped memory managment
+ SOA (Structure Of Arrays) memory layout by default
+ Automatic vectorization
