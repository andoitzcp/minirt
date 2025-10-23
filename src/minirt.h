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
    struct s_elements *el;
    struct s_intersects *next;
} t_intersects;

// TODO initialize intersects structure somewhere
typedef struct s_ray
{
    struct s_tuple o; // origin (point)
    struct s_tuple d; // direction (vector)
    struct s_intersects *i;
} t_ray;


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
    struct s_tuple p;
    float abr; // Ambient Brightness Ratio
    struct s_color col;
} t_light;

typedef struct s_sphere
{
    struct s_tuple p;
    float dia; // Diameter
    struct s_color col;
} t_sphere;

typedef struct s_cylinder
{
    struct s_tuple p;
    struct s_tuple v;
    float dia; // Diameter
    float hei; // Height
    struct s_color col;
} t_cylinder;

typedef struct s_plane
{
    struct s_tuple p;
    struct s_tuple v;
    struct s_color col;
} t_plane;

typedef union u_eldata
{
    struct s_sphere sp;
    struct s_cylinder cy;
    struct s_plane pl;
} t_eldata;

typedef struct s_elements
{
    enum e_elid type;
    union u_eldata elda;
} t_elements;

typedef struct s_data
{
    struct s_amblight ali;
    struct s_camera c;
    struct s_light l;
    struct s_resolution res;
    struct s_elements **els;
    struct s_line *lines;
    struct s_re **re_el_types[RE_TYPE_QTY + 1];
    struct s_re **re_float;
    struct s_re **re_int;
    uint nels;
    uint8_t emf;
} t_data;

/*******************************************************************************/
/* Function definitions                                                        */
/*******************************************************************************/

/* parse */
void parse(t_data *data, char *filepath);
void get_raw_content(t_data *data, char *filepath);

/* lines */
char ***split_line(char *s);
t_line *build_line_node(t_data *data, char ***line, int type);
void append_line_node(t_line **head, t_line *node);
void process_line(t_data *data, char *s);

/* get data basic */
uint8_t get_point_data(t_data *data, t_tuple *tuple, char **s);
uint8_t get_vector_data(t_data *data, t_tuple *tuple, char **s);
uint8_t get_color_data(t_data *data, t_color *color, char **s);

/* get data common elements */
uint8_t get_amblight_data(t_data *data, t_amblight *node, char ***line);
uint8_t get_camera_data(t_data *data, t_camera *node, char ***line);
uint8_t get_light_data(t_data *data, t_light *node, char ***line);

/* get data geometric elements*/
uint8_t get_sphere_data(t_data *data, t_sphere *node, char ***line);
uint8_t get_plane_data(t_data *data, t_plane *node, char ***line);
uint8_t get_cylinder_data(t_data *data, t_cylinder *node, char ***line);

/* check boundaries */
uint8_t check_color_bounds(t_color *color);
uint8_t check_nvector_bounds(t_tuple *vector);

/* parse utils*/
int get_element_id(char *s);
void classify_raw_content_into_elements(t_rawlines **head);
void trim_raw_content_ws_nodes(t_rawlines **head);
int8_t has_raw_content_invalid_lines(t_rawlines **head);
uint get_element_qty(t_rawlines **head);
void append_rawline_node(t_data *data, char *content);
void breakdown_rawlines(t_rawlines **head);

/* input validation */
int8_t is_valid_input_file(char *filepath);
int8_t is_valid_data(t_data *data);

void init(t_data *data);

/* exit */
int ft_exit(t_data *data, char *s);
void free_lines(t_line **head);
void free_els(t_elements **array);

/* debugging */
void print_ds_rawl(t_rawlines **head);
void print_line_els(char ***line);
void print_element_list(t_elements **el);
void print_intersections(t_intersects **head);


/* color */
t_color		color_set(float r, float g, float b);
t_color		color_limit(t_color c);
t_color		color_clamp(t_color c);
t_color		color_add(t_color a, t_color b);
t_color		color_sub(t_color a, t_color b);
t_color		color_scale_up(t_color a, float n);
t_color		color_scale_down(t_color a, float n);
t_color		color_blend(t_color a, t_color b);

/* canvas */
t_canvas	*canvas_init(int width, int height);
void		canvas_set_color(t_canvas *can, t_color c);
int			canvas_set_pixel(t_canvas *can, int x, int y, t_color c);
t_color		canvas_get_pixel(t_canvas can, int x, int y);
int			canvas_to_ppm(t_canvas can, char *name);

/* ray */
t_ray ray_new(t_tuple origin, t_tuple direction);
t_tuple position(t_ray ray, float t);

/* intersect */
t_intersect_old intersect_sp_old(t_ray *ray, t_sphere *sp);
void calc_ray_sp_intersects(float *array, t_ray *ray, t_sphere *sp);
void calc_ray_pl_intersects(float *array, t_ray *ray, t_plane *pl);
void calc_ray_cy_intersects(float *array, t_ray *ray, t_cylinder *cy);
t_intersects *new_intersect(t_elements *el, float i);
void insert_ray_intersect(t_intersects **head, t_intersects *node);
void get_ray_el_intersects(t_ray *ray, t_elements *el);
float hit(t_intersects **head);

#endif // MINIRT_H_
