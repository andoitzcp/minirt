| malloc en...      | tipo          | dueño final   | campo / variable      | se libera en...       |
| ----------------- | ------------- | ------------- | --------------------- | --------------------- |
| canvas_init()     | t_canvas      | canvas        | canvas                | destroy_canvas()      |
| canvas_init()     | t_color *     | canvas        | canvas->pixel_block   | destroy_canvas()      |
| canvas_init()     | t_color **    | canvas        | canvas->image         | destroy_canvas()      |
| ----------------- | ------------- | ------------- | --------------------- | --------------------- |
| new_object()      | t_object      | world         | world->objs           | destroy_objs()        |
| new_intersect()   | t_intersects  | ray           | ray->i                | destroy_intersects()  |


[new_intersect](src/intersect.c) line 19
[build_element_node](src/parse.c) line 33
[alloc_els](src/lines.c) line 15
[canvas_init](src/canvas.c) line 15
[new_object](src/object.c) line 15

inc/libregex/test/src/parse.c:7
inc/libregex/src/re_node_utils.c:1
inc/libregex/test/src/build_re_node.c:15
inc/libregex/src/new_regex.c:1
inc/libregex/src/ft_chrstrchr.c:1
inc/libregex/src/libregex_priv.h:1
inc/libregex/src/ft_strdup.c:1
inc/libregex/src/ft_strndup.c:1
inc/libregex/src/ft_calloc.c:3

inc/libft/libft.h:1
inc/libft/ft_split.c:1
inc/libft/ft_strmapi.c:1
inc/libft/Makefile:1
inc/libft/ft_strjoin.c:1
inc/libft/ft_itoa.c:1
inc/libft/ft_substr.c:1
inc/libft/ft_strdup.c:1
inc/libft/ft_gnl.c:1
inc/libft/ft_strtrim.c:1
inc/libft/ft_atoh.c:1
inc/libft/ft_calloc.c:3
