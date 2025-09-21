# linmath

Linear math and algebra library for 42 projects

### References : 
* [Ray tracer Challenge - Jamis Buck](./res/)

# 1.Tuples: points and vectors

* Tuple = {x,y,z,w} = float[4] or {float[3], int}
    * Point = {x, y, z, w = 1}
    * Vector = {x, y, z, w = 0}

## Operations

### Addition

* t1 + t2 = {x1, y1, z1, w1} + {x2, y2, z2, w2} = {x1 + x2, y1 + y2, z1 + z2, w1 + w2}

    * Point + Point = ERROR (w = 2)
    * Point + Vector = Point (w = 1)
    * Vector + Point = Point (w = 1)
    * Vector + Vector = Vector (w = 0)

### Substraction

* t1 - t2 = {x1, y1, z1, w1} - {x2, y2, z2, w2} = {x1 - x2, y1 - y2, z1 - z2, w1 - w2}

    * Point - Point = Vector (w = 0)
    * Point - Vector = Point (w = 1)
    * Vector - Point = ERROR (w = -1)
    * Vector - Vector = Vector (w = 0)

## Vector only operations

### Scalar multiplication/division:
* It changes the vector's length by n
    * v * n = {x * n, y * n, z * n}
    * v / n = {x / n, y / n, z / n}

### Negation:
* It flips the vector's direction
* Is the same as multiplying it by -1
    * !v = v * -1 = {-x, -y, -z}

### Magnitude:
* It is the distance represented by a vector
    * Magnitude(v) = sqrt(x * x + y * y + z * z)

### Normalization:
* Unit vector = vector whichs magnitude = 1
* Unit vectors are useful to represent direction without distance
* Normalization occurs by dividing each coordinate by the vectors magnitude
* Normalized(v) = {x/magnitude(v), y/magnitude(v), z/magnitude(v)}

### Dot product:
* Represents the angle between 2 vectors
* Supposing unit vectors:
    * The smaller the dot product the greater the angle. < (v1 · v2) <-> > angle(v1, v2)
    * A dot product of 1 means the vectors are identical. v1 · v2 = 1 <-> v1 = v2
    * A dot product of -1 means the vectors point opposite directions. v1 · v2 = -1 <-> v1 = -v2
* Dot product is calculated adding the products of each coordinate
    * v1 · v2 = x1 * x2 + y1 * y2 + z1 * z2

### Cross product:
* Represents a vector perpendicular to two given vectors
* Any vector crossed with itself (parallel to itself) is the zero vector -> v x v = {0, 0, 0}
* Cross product formula:
    * v1 x v2 = { y1 * z2 - z1 * y2, z1 * x2 - x1 * z2, x1 * y2 - y1 * x2 }
