# minirt
mini ray tracing project

## Resources

Some important lectures:

- (https://gabrielgambetta.com/computer-graphics-from-scratch)[Computer graphics from scractch]
- (https://raytracing.github.io/)[Ray tracing series]
	+ (https://raytracing.github.io/books/RayTracingInOneWeekend.html)[Ray tracing in one weekend]
	+ (https://raytracing.github.io/books/RayTracingTheNextWeek.html)[Ray tracing the next week]
	+ (https://raytracing.github.io/books/RayTracingTheRestOfYourLife.html)[Ray tracing the rest of your life]
- (./res/The\ Ray\ Tracer\ Challenge-Pragmatic\ Bookshelf\ \(2019\)\ -\ Jamis\ Buck.pdf)[Ray tracer Challenge]

## Tasks

- [ ] Parser
    - [ ] Check correct input
        - [ ] file extension must be "\*.rt"
        - [ ] must have file access
        - [ ] test
    - [ ] Check for correct content
        - [ ] using regex library check for correct line structure.
            - [ ] correct number of fiels.
            - [ ] correct number of elements per field
            - [ ] test
        - [ ] check for correct floats and ints inside lines
            - [ ]test
        - [ ] check for bounds
            - [ ] test
        - [ ] infor correctly stored in structure
            - [ ] test
    - [ ] Memory leaks
    - [ ] Build a regex engine (libregex)
        - [x] has **new_re()** function
        - [x] has **match()** function
        - [ ] has **free_re()** function
        - [ ] has **NO memory leaks**
        - [ ] test
        - [ ] Memory leaks
- [ ] Math
    - [ ] Tuples
    - [ ] Colors
    - [ ] Canvas
    - [ ] Matrices
    - [ ] Memory leaks
- [ ] Graphics
    - [ ] Intersections
    - [ ] Light and shading
    - [ ] Making a scene
    - [ ] shadows
    - [ ] Planes
    - [ ] Reflection and refraction
    - [ ] Cubes
    - [ ] Cylinders
    - ...
    - [ ] Memory leaks
