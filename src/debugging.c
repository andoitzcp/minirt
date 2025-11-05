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

void print_matrix(t_matrix *m)
{
    printf("Matrix: %p\n", m);
    printf("\tm[0][0]: %f\n", m->value[0][0]);
    printf("\tm[0][1]: %f\n", m->value[0][1]);
    printf("\tm[0][2]: %f\n", m->value[0][2]);
    printf("\tm[0][3]: %f\n", m->value[0][3]);
    printf("\tm[1][0]: %f\n", m->value[1][0]);
    printf("\tm[1][1]: %f\n", m->value[1][1]);
    printf("\tm[1][2]: %f\n", m->value[1][2]);
    printf("\tm[1][3]: %f\n", m->value[1][3]);
    printf("\tm[2][0]: %f\n", m->value[2][0]);
    printf("\tm[2][1]: %f\n", m->value[2][1]);
    printf("\tm[2][2]: %f\n", m->value[2][2]);
    printf("\tm[2][3]: %f\n", m->value[2][3]);
    printf("\tm[3][0]: %f\n", m->value[3][0]);
    printf("\tm[3][1]: %f\n", m->value[3][1]);
    printf("\tm[3][2]: %f\n", m->value[3][2]);
    printf("\tm[3][3]: %f\n", m->value[3][3]);

}

void print_color(t_color *c)
{
    printf("\t\tColor: %p\n", c);
    printf("\t\t\tr: %f\n", c->r);
    printf("\t\t\tg: %f\n", c->g);
    printf("\t\t\tb: %f\n", c->b);
}

void print_raw_sphere(t_raw_sphere *s)
{
    printf("\tSphere: %p\n", s);
    print_tuple(&(s->p));
    printf("\tdiameter: %f\n", s->dia);
    print_color(&(s->col));
}

void print_raw_plane(t_raw_plane *p)
{
    printf("\tPlane: %p\n", p);
    print_tuple(&(p->p));
    print_tuple(&(p->v));
    print_color(&(p->col));
}

void print_raw_cylinder(t_raw_cylinder *c)
{
    printf("\tCylinder: %p\n", c);
    print_tuple(&(c->p));
    print_tuple(&(c->v));
    print_color(&(c->col));
    printf("\t\tDiameter: %f\n", c->dia);
    printf("\t\tHeigh: %f\n", c->hei);
}

void print_raw_element(t_elements *el)
{
    printf("Printing element:%p\n", el);
    printf("\tType: %d\n", el->type);
    if (el->type == ELID_SP)
        print_raw_sphere(&el->relda.sp);
    if (el->type == ELID_PL)
        print_raw_plane(&el->relda.pl);
    if (el->type == ELID_CY)
        print_raw_cylinder(&el->relda.cy);
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

void print_parsed_content(t_data *data)
{
    printf("Printing parsed content:%p\n", data);
    printf("Printing Camera: %p", &data->raw.c);
    printf("\t fov = %d\n", data->raw.c.fov);
    printf("\t position:\n");
    print_tuple(&data->raw.c.p);
    printf("\t direction:\n");
    print_tuple(&data->raw.c.v);
    printf("\n");

    printf("Printing Ambient Light: %p", &data->raw.ali);
    printf("\t ratio = %f\n", data->raw.ali.ratio);
    printf("\t color:\n");
    print_color(&data->raw.ali.col);
    printf("\n");

    printf("Printing Light: %p", &data->raw.l);
    printf("\t ratio = %f\n", data->raw.l.abr);
    printf("\t position:\n");
    print_tuple(&data->raw.l.p);
    printf("\t color:\n");
    print_color(&data->raw.l.col);
    printf("\n");

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
