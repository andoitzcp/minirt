#ifndef MINIRT_H_
#define MINIRT_H_

/*******************************************************************************/
/* Includes                                                                    */
/*******************************************************************************/

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../inc/libft/libft.h"
#include "../../minilibx-linux/mlx.h"

/*******************************************************************************/
/* Data definitions                                                            */
/*******************************************************************************/

#define WS_CHARS " \t\n"

#define EL_CAMERA_ID "c"
#define EL_LIGHT_ID "l"
#define EL_SPHERE_ID "sp"
#define EL_PLANE_ID "pl"
#define EL_SQUARE_ID "sq"
#define EL_CYLINDER_ID "cy"
#define EL_TRIANGLE_ID "tr"
#define EL_BLANK_LINE_ID ""

// Exit mode definitions

#define ERRORS000 "Error\n"
#define ERRORS001 "minirt:init:append_rawline_node:"
#define ERRORS002 "minirt:init:provided .rt file has invalid lines\n"
#define ERRORS003 "minirt:init:init_elements"
#define ERRORS004 "minirt:init:init_element_array:rawline linked list size and stored element quantity differ\n"


typedef enum e_elid
{
    ELID_C,
    ELID_L,
    ELID_SP,
    ELID_PL,
    ELID_SQ,
    ELID_CY,
    ELID_TR,
    ELID_BLANK_LINE,
    ELID_INVALID
} t_elid;

typedef struct s_rawlines
{
    enum e_elid elid;
    char *line;
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
} t_exitmodeflags;

typedef struct s_amblight
{
    float ratio;
    uint col;
} t_amblight;

typedef struct s_resolution
{
    uint x_sz;
    uint y_sz;
} t_resolution;

typedef struct s_point
{
    float x;
    float y;
    float z;
} t_point;

typedef struct s_normvector
{
    float r;
    float s;
    float t;
} t_normvector;

typedef struct s_camera
{
    struct s_point p;
    struct s_normvector nv;
    uint8_t fov; // Fiel Of View in degrees
} t_camera;

typedef struct s_light
{
    struct s_point p;
    float abr; // Ambient Brightness Ratio
    uint col;
} t_light;

typedef struct s_sphere
{
    struct s_point p;
    float dia; // Diameter
    uint col;
} t_sphere;

typedef struct s_plane
{
    struct s_point p;
    struct s_normvector nv;
    uint col;
} t_plane;

typedef struct s_square
{
    struct s_point p;
    struct s_normvector nv;
    float ssz; // square Size SiZe
    uint col;
} t_square;

typedef struct s_cylinder
{
    struct s_point p;
    struct s_normvector nv;
    float dia; // Diameter
    float hei; // Height
    uint col;
} t_cylinder;

typedef struct s_triangle
{
    struct s_point p1;
    struct s_point p2;
    struct s_point p3;
    uint col;
} t_triangle;

typedef union u_eldata
{
    struct s_camera c;
    struct s_light l;
    struct s_sphere sp;
    struct s_plane pl;
    struct s_square sq;
    struct s_cylinder cy;
    struct s_triangle tr;
} t_eldata;

typedef struct s_elements
{
    enum e_elid type;
    union u_eldata elda;
} t_elements;

typedef struct s_data
{
    struct s_amblight ali;
    struct s_resolution res;
    struct s_elements *els;
    struct s_rawlines **rawl;
    uint nels;
    uint8_t emf;
} t_data;

/*******************************************************************************/
/* Function definitions                                                        */
/*******************************************************************************/

// parser
void parse(void);

// exit
int ft_exit(t_data *data, char *s);

#endif // MINIRT_H_
