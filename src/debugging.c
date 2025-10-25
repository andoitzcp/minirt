#include "minirt.h"

void print_line_els(char ***line)
{
    size_t i;
    size_t j;

    printf("<line:%p>\n", line);
    i = 0;
    while (line[i] != NULL)
    {
        j = 0;
        printf("\t<element[%ld]:%p>\n", i, line[i]);
        while (line[i][j] != NULL)
        {
            printf("\t\t<content[%ld]:%s></content>\n", j, line[i][j]);
            j++;
        }
        i++;
        printf("\t</element>\n");
    }
    printf("</line>\n");
    return ;
}

void print_tuple(t_tuple *t)
{
    printf("\t\tTuple: %p\n", t);
    printf("\t\t\tx: %f\n", t->x);
    printf("\t\t\ty: %f\n", t->y);
    printf("\t\t\tz: %f\n", t->z);
    printf("\t\t\tw: %f\n", t->w);
}

void print_color(t_color *c)
{
    printf("\t\tColor: %p\n", c);
    printf("\t\t\tr: %f\n", c->r);
    printf("\t\t\tg: %f\n", c->g);
    printf("\t\t\tb: %f\n", c->b);
}

void print_raw_sphere(t_sphere *s)
{
    printf("\tSphere: %p\n", s);
    print_tuple(&(s->p));
    print_color(&(s->mat.color));
    printf("\t\tDiameter: %f\n", s->dia);
}

void print_raw_plane(t_plane *p)
{
    printf("\tPlane: %p\n", p);
    print_tuple(&(p->p));
    print_tuple(&(p->v));
    print_color(&(p->mat.color));
}

void print_raw_cylinder(t_cylinder *c)
{
    printf("\tCylinder: %p\n", c);
    print_tuple(&(c->p));
    print_tuple(&(c->v));
    print_color(&(c->mat.color));
    printf("\t\tDiameter: %f\n", c->dia);
    printf("\t\tHeigh: %f\n", c->hei);
}

void print_raw_element(t_elements *el)
{
    printf("Printing element:%p\n", el);
    printf("\tType: %d\n", el->type);
    if (el->type == ELID_SP)
        print_raw_sphere(&el->elda.sp);
    if (el->type == ELID_PL)
        print_raw_plane(&el->elda.pl);
    if (el->type == ELID_CY)
        print_raw_cylinder(&el->elda.cy);
}

void print_raw_element_list(t_elements **el)
{
    int i;

    i = 0;
    while ((el[i]) != NULL)
    {
        print_raw_element(el[i]);
        i++;
    }
}

void print_intersections(t_intersects **head)
{
    t_intersects *current;
    int i;

    current = *head;
    i = 0;
    printf("Printing intersections: *head %p\n", *head);
    while (current)
    {
        printf("# %d, v: %f\n", i, current->i);
        current = current->next;
        i++;
    }
    printf("End\n");

}
