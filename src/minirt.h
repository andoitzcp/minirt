#ifndef MINIRT_H_
#define MINIRT_H_

/*******************************************************************************/
/* Includes                                                                    */
/*******************************************************************************/

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include "../inc/libft/libft.h"
#include "../inc/libregex/src/libregex.h"
#include "../../minilibx-linux/mlx.h"
#include "../inc/liblinmath/src/linmath.h"

/*******************************************************************************/
/* Data definitions                                                            */
/*******************************************************************************/

#define TRUE 1
#define FALSE 0

#define WS_CHARS " \t\n"

#define EL_AMBLIGHT_ID "A "
#define EL_CAMERA_ID "C "
#define EL_LIGHT_ID "L "
#define EL_SPHERE_ID "sp "
#define EL_PLANE_ID "pl "
#define EL_SQUARE_ID "sq "
#define EL_CYLINDER_ID "cy "
#define EL_TRIANGLE_ID "tr "
#define EL_BLANK_LINE_ID ""

#define RE_TYPE_QTY 9
#define RE_AMBLIGHT "^A "
#define RE_CAMERA "^C "
#define RE_LIGHT "^L "
#define RE_SPHERE "^sp "
#define RE_PLANE "^pl "
#define RE_SQUARE "^sq "
#define RE_CYLINDER "^cy "
#define RE_TRIANGLE "^tr "
#define RE_BLANK_LINE "^\n$"

/* Exit mode definitions */

#define ERRORS000 "Error\n"
#define ERRORS001 "minirt:init:init_re_element_types:Invalid regex input"
#define ERRORS002 "minirt:init:provided .rt file has invalid lines\n"
#define ERRORS003 "minirt:init:init_elements"
#define ERRORS004 "minirt:init:init_element_array:rawline linked list size and stored element quantity differ\n"
#define ERRORS005 "minirt:parse:is_valid_input_file:not a valid path"
#define ERRORS006 "minirt:parse:get_raw_content:unable to open the file"
#define ERRORS007 "minirt:parse:process_line:Invalid lines detected"
#define ERRORS008 "minirt:init:init_re_element_types:Malloc error"
#define ERRORS009 "minirt:parse:build_line_node:Malloc error"
#define ERRORS010 "minirt:parse:check_unique_elements:More than 1 unique element detected"
#define ERRORS011 "minirt:parse:build_element_node:Malloc error"

/* Othe definitions */
#define MAX_PATH_LENGTH 4096
#define RT_FILE_EXTENSION ".rt"
#define MAX_RGB_STR_LEN 11
#define RGB_STR_ELEMENTS 3
#define RGB_STR_VALID_CHARSET "0123456789,"

#define ELQTY 8
#define RE_FLOAT  "^-{0}{1}[0-9]*\\.{0}{1}[0-9]{1}$"
#define RE_INT  "^-{0}{1}[0-9]{1}$"
#define RE_EL_A "^ *A {1}[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} *$"
#define RE_EL_C "^ *C {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1} *$"
#define RE_EL_L "^ *L {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} *$"
#define RE_EL_SP "^ *sp {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} *$"
#define RE_EL_PL "^ *pl {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} *$"
#define RE_EL_CY "^ *cy {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} {1}[^, ]{1} {1}[^, ]{1} {1}[^, ]{1},[^, ]{1},[^, ]{1} *$"
#define RE_EL_BLANK "^\n$"

#define DEF_RESOLUTION_X 1920
#define DEF_RESOLUTION_Y 1080

typedef enum e_elid
{
    ELID_NULL,
    ELID_A = 0,
    ELID_C = 1,
    ELID_L = 2,
    ELID_SP = 3,
    ELID_PL = 4,
    ELID_CY = 5,
    ELID_BLANK_LINE = 6,
    ELID_INVALID
} t_elid;

typedef struct s_line
{
    int8_t type;
    char ***content;
    struct s_line *next;
} t_line;

typedef struct s_intarray
{
    int *array;
    size_t len;
} t_intarray;

typedef struct s_rawlines
{
    enum e_elid elid;
    char ***line;
    int element_qty;
    struct s_rawlines *next;
} t_rawlines;

/*
** The idea of this enums is to set flags in the data structure when some
** structure is allocated to the pass to the ft_exit function which will lookup
** into this flag and will free the necessary structures.
 */
typedef enum e_exitmodeflags{
  EMF_NOFREE = 1 << 0,
  EMF_RAWL = 1 << 1,
  EMF_ELS = 1 << 2,
  EMF_REET = 1 << 3, // RegEx Element types
  EMF_PERROR = 1 << 4,
} t_exitmodeflags;

typedef struct s_resolution
{
    uint x_sz;
    uint y_sz;
} t_resolution;

typedef struct s_color
{
    float r;
    float g;
    float b;
} t_color;

//------
typedef struct s_raw_amblight
{
    float ratio;
    struct s_color col;
} t_raw_amblight;

typedef struct s_raw_camera
{
    struct s_tuple p;
    struct s_tuple v;
    uint8_t fov; // Fiel Of View in degrees
} t_raw_camera;

typedef struct s_raw_light
{
    struct s_tuple p;
    float abr; // Ambient Brightness Ratio
    struct s_color col;
} t_raw_light;

typedef struct s_raw_sphere
{
    struct s_tuple p;
    float dia; // Diameter
    struct s_color col;
} t_raw_sphere;

typedef struct s_raw_cylinder
{
    struct s_tuple p;
    struct s_tuple v;
    float dia; // Diameter
    float hei; // Height
    struct s_color col;
} t_raw_cylinder;

typedef struct s_raw_plane
{
    struct s_tuple p;
    struct s_tuple v;
    struct s_color col;
} t_raw_plane;
//------

typedef struct s_canvas
{
	int		width;
	int		height;
	t_color	*pixel_block;
	t_color	**image;
} t_canvas;

typedef struct s_intersect_old
{
    int q; //qty of intersections
    float i[2]; //intersections
} t_intersect_old;

typedef struct s_intersects
{
    float i; //intersections
    struct s_object *obj;
    struct s_intersects *next;
} t_intersects;

// TODO initialize intersects structure somewhere
typedef struct s_ray
{
    struct s_tuple o; // origin (point)
    struct s_tuple d; // direction (vector)
    struct s_intersects *i;
} t_ray;

typedef struct s_material
{
	struct s_color	color;
	float			ambient;
	float			diffuse;
	float			specular;
	float			shininess;
}	t_material;

typedef struct s_amblight
{
    float ratio;
    struct s_color col;
} t_amblight;

typedef struct s_camera
{
    struct s_tuple p;
    struct s_tuple v;
    uint8_t fov; // Fiel Of View in degrees
} t_camera;

typedef struct s_light
{
    struct s_tuple	p;
    float			abr; // Ambient Brightness Ratio
    struct s_color	col;

} t_light;

typedef struct s_sphere
{
	// TODO eliminar p y dia ??
    struct s_tuple		p;
	struct s_matrix		trans; //MERGE
	struct s_material	mat;
} t_sphere;

typedef struct s_cylinder
{
    struct s_tuple p;
    struct s_tuple v;
    float dia; // Diameter
    float hei; // Height
    t_matrix t;
    t_material mat;
} t_cylinder;

typedef struct s_plane
{
    struct s_tuple p;
    struct s_tuple v;
    t_matrix t;
    t_material mat;
} t_plane;

typedef union u_eldata
{
    struct s_sphere sp;
    struct s_cylinder cy;
    struct s_plane pl;
} t_eldata;

typedef struct s_elements
{
    enum e_elid type; // element data type (sp, pl, cy)
    union u_eldata elda; // data
    union u_eldata relda; // raw elements data
} t_elements;

typedef struct s_raw_data
{
    struct s_raw_amblight ali;
    struct s_raw_camera c;
    struct s_raw_light l;
    struct s_resolution res;
    struct s_elements **els;
    struct s_line *lines;
    struct s_re **re_el_types[RE_TYPE_QTY + 1];
    struct s_re **re_float;
    struct s_re **re_int;
    uint nels;
} t_raw_data;


typedef struct s_object
{
    enum e_elid type; // element data type (sp, pl, cy)
    union u_eldata data; // raw data
    struct s_object *next;
} t_object;

typedef struct s_comps
{
    struct s_object *obj; // object
    struct s_tuple point; // point
    struct s_tuple eyev; // eye vector
    struct s_tuple normv; // normal vector
    struct s_light light; // light
    float t;
    int is_shadowed; // object shadowe yes=1 no=0
    int is_inside;
} t_comps;

typedef struct s_world
{
    struct s_resolution res;
    struct s_camera c;
    struct s_amblight ali;
    struct s_light l;
    struct s_object *objs;
} t_world;

typedef struct s_data
{
    struct s_raw_data raw;
    struct s_world world;
    uint8_t emf;


} t_data;

/*******************************************************************************/
/* Function definitions                                                        */
/*******************************************************************************/

/* parse */
void	parse(t_data *data, char *filepath);
void	get_raw_content(t_data *data, char *filepath);

/* lines */
char	***split_line(char *s);
t_line	*build_line_node(t_data *data, char ***line, int type);
void	append_line_node(t_line **head, t_line *node);
void	process_line(t_data *data, char *s);

/* get data basic */
uint8_t	get_point_data(t_data *data, t_tuple *tuple, char **s);
uint8_t	get_vector_data(t_data *data, t_tuple *tuple, char **s);
uint8_t	get_color_data(t_data *data, t_color *color, char **s);

/* get data common elements */
uint8_t	get_amblight_data(t_data *data, t_raw_amblight *node, char ***line);
uint8_t	get_camera_data(t_data *data, t_raw_camera *node, char ***line);
uint8_t	get_light_data(t_data *data, t_raw_light *node, char ***line);

/* get data geometric elements*/
uint8_t	get_sphere_data(t_data *data, t_raw_sphere *node, char ***line);
uint8_t get_plane_data(t_data *data, t_raw_plane *node, char ***line);
uint8_t get_cylinder_data(t_data *data, t_raw_cylinder *node, char ***line);

/* check boundaries */
uint8_t	check_color_bounds(t_color *color);
uint8_t	check_nvector_bounds(t_tuple *vector);

/* input validation */
int8_t	is_valid_input_file(char *filepath);
int8_t	is_valid_data(t_data *data);

void	init(t_data *data);

/* exit */
int		ft_exit(t_data *data, char *s);
void	free_lines(t_line **head);
void	free_els(t_elements **array);

/* debugging */
void	print_ds_rawl(t_rawlines **head);
void 	print_line_els(char ***line);
void 	print_raw_element_list(t_elements **el);
void 	print_intersections(t_intersects **head);
void print_matrix(t_matrix *m);

/* color */
t_color		color_set(float r, float g, float b);
t_color		color_limit(t_color c);
t_color		color_clamp(t_color c);
t_color		color_add(t_color a, t_color b);
t_color		color_sub(t_color a, t_color b);
t_color		color_scale_up(t_color a, float n);
t_color		color_scale_down(t_color a, float n);
t_color		color_blend(t_color a, t_color b);
t_color		color_convert_from_raw(t_color color);

/* canvas */
t_canvas	*canvas_init(int width, int height);
void		canvas_set_color(t_canvas *can, t_color c);
int			canvas_set_pixel(t_canvas *can, int x, int y, t_color c);
t_color		canvas_get_pixel(t_canvas can, int x, int y);
int			canvas_to_ppm(t_canvas can, char *name);

/* ray */
t_ray	ray_new(t_tuple origin, t_tuple direction);
t_tuple	position(t_ray ray, float t);
t_tuple reflect(t_tuple in, t_tuple normal);

// TODO eliminar funciones transform ??
/* transform */
t_ray	transform(t_ray r, t_matrix m);
void	set_transform_old(t_elements *el, t_matrix m);
void	set_transform(t_object *object, t_matrix m);
t_matrix	sphere_transform(t_sphere sphere);
t_tuple		transform_back(t_matrix transform, t_tuple point);
t_matrix view_transform(t_tuple from, t_tuple to, t_tuple up);

/* sphere*/
t_sphere new_sphere(void);
void set_sphere_from_raw_data(t_sphere *sp, t_raw_sphere *rsp);

/* plane */
t_plane new_plane(void);
void set_plane_from_raw_data(t_plane *pl, t_raw_plane *rpl);

/* cylinder */
t_cylinder new_cylinder(void);
void set_cylinder_from_raw_data(t_cylinder *cy, t_raw_cylinder *rcy);

/* light */
t_light new_light(t_tuple point, t_color color, float ratio);
t_light convert_light_from_raw(t_raw_light raw_light);
t_light def_light(void);

/* amblight */
t_amblight new_amblight(t_color color, float ratio);
t_amblight convert_amblight_from_raw(t_raw_amblight raw_amblight);
t_amblight def_amblight(void);

/* camera */
t_camera new_camera(t_tuple point, t_tuple vector, float fov);
t_camera convert_camera_from_raw(t_raw_camera raw_camera);
t_camera def_camera(void);

/* material */
t_material def_material(void); // temporal cuando se mergee borrar
void set_material(t_object *object, t_material material);

/* object */
t_object *new_object(int type, t_matrix *transform, t_material *material);
void object_append(t_object **head, t_object *node);

/* world */
t_world def_world(void);

// TODO elegir entre sphere() y new_sphere()
/* sphere */
t_sphere	new_sphere(void);
void		set_sphere_from_raw_data(t_sphere *sp, t_raw_sphere *rsp);
t_sphere	*set_sphere_transform(t_sphere *s, t_matrix trans);
t_matrix	get_sphere_transform(t_sphere s);
t_tuple		sphere_normal_at(t_sphere s, t_tuple p);

/* plane */
t_plane	new_plane(void);
void	set_plane_from_raw_data(t_plane *pl, t_raw_plane *rpl);
t_tuple	plane_normal_at(t_plane plane, t_tuple point);

/* cylinder */
t_cylinder	new_cylinder(void);
void		set_cylinder_from_raw_data(t_cylinder *cy, t_raw_cylinder *rcy);
t_tuple	cylinder_normal_at(t_cylinder cylinder, t_tuple point);

/* light */
t_light	convert_light_from_raw(t_raw_light raw_light);
t_light	new_light(t_tuple point, t_color color, float ratio);
t_light	def_light(void);

/* amblight */
t_amblight	new_amblight(t_color color, float ratio);
t_amblight 	convert_amblight_from_raw(t_raw_amblight raw_amblight);
t_amblight 	def_amblight(void);

/* camera */
t_camera	new_camera(t_tuple point, t_tuple vector, float fov);
t_camera 	convert_camera_from_raw(t_raw_camera raw_camera);
t_camera 	def_camera(void);

/* material */
t_material	def_material(void);
t_material new_material(t_color color, float *specs);
void		set_material(t_object *object, t_material material);

/* world */
t_world	def_world(void);
void intersect_world(t_world *world, t_ray *ray);
t_comps prep_comps(t_intersects *intersection, t_ray *ray);
t_color shade_hit(t_world *world, t_comps *comps);
t_color color_at(t_world *world, t_ray *ray);

/* intersect */
t_intersect_old	intersect_sp_old(t_ray *ray, t_sphere *sp);
void			calc_ray_sp_intersects(float *array, t_ray *ray, t_sphere *sp);
void 			calc_ray_pl_intersects(float *array, t_ray *ray, t_plane *pl);
void 			calc_ray_cy_intersects(float *array, t_ray *ray, t_cylinder *cy);
t_intersects *new_intersect(t_object *obj, float i);
void			insert_ray_intersect(t_intersects **head, t_intersects *node);
void get_ray_el_intersects(t_ray *ray, t_object *obj);
float			hit(t_intersects **head);


/* lighting */
t_color	lighting(t_material material, t_tuple point, t_light light,
				t_tuple eyev, t_tuple normalv);

/* object */
t_object *new_object(int type, t_matrix *transform, t_material *material);
void object_append(t_object **head, t_object *node);

#endif // MINIRT_H_
