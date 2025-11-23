| malloc en...      | tipo          | dueño final   | campo / variable      | se libera en...       |
| ----------------- | ------------- | ------------- | --------------------- | --------------------- |
| canvas_init()     | t_canvas      | canvas        | canvas                | destroy_canvas()      |
| canvas_init()     | t_color *     | canvas        | canvas->pixel_block   | destroy_canvas()      |
| canvas_init()     | t_color **    | canvas        | canvas->image         | destroy_canvas()      |
| ----------------- | ------------- | ------------- | --------------------- | --------------------- |
| new_object()      | t_object      | world         | world->objs           | destroy_objs()        |
| new_intersect()   | t_intersects  | ray           | ray->i                | destroy_intersects()  |

