# lite programming language
**Assignment**
````
x: 1, 2, 3
x: ++

# x = 2, 3, 4 
# all variables are arrays and assignments are looped by default.
````
**Keywords**
````
procedure test: none
  skip
  
primitive _bool:
  true, false
  
composite Vector2:
  x: f32
  y: f32
````
Features
------
+ Strong typing
+ Safe and simple concurrency
+ Powerful looping
+ Deterministic scoped memory managment
+ SOA (Structure Of Arrays) memory layout by default
+ Automatic vectorization
