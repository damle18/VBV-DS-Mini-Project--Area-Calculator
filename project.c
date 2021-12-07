/*
---SURFACE AREA CALCULATOR---
-Efficient tool used to calculate the surface areas of various regular shapes.
-DS Mini Project for Academic Year 2021-22
-Developed by: Harsh Bhat(22108)
               Shreyas Chandolkar(22112)
               Atharva Chirputkar(22114)
               Kaustubh Damle(22115)   
*/

//Header files
#include<stdio.h>
#include<string.h>
#include<math.h>
//Macro defintion
#define pi 3.14


//Area of square
void a_square(float x, float *ptr){
    *ptr=x*x;
}


//Area of circle
void a_circle(float x, float *ptr){
    *ptr=pi*x*x;
}


//Area of ellipse
float a_ellipse(float maj, float min){
    return (pi*maj*min);
}


//Area of trapezium
float a_trapezium(float ht, float s1, float s2){
    return (0.5*ht*(s1+s2));
}


//Area of rectangle
void a_rect(float x, float y, float *ptr){
    *ptr=x*y;
}


//Area of pentagon
float a_pent(float side){
    return 1.72*(side*side);
}


//Area of hexagon
float a_hexagon(float len){
    return (2.6*len*len);
}


//Area of triangle
float a_triangle(float a, float b, float c){
    float s=(a+b+c)/2;
    float area=sqrt(s*(s-a)*(s-b)*(s-c));
    //Using typecasting method to convert int 0 to float 0
    if(area==(float)0){
        printf("\nInvalid triangle.");
    }
    else return area;
}


//Area of cuboid or cube
float a_cuboid(float x,float y, float z){
    float area;
    area=2*((x*y)+(y*z)+(z*x));
    return area;
}


//Area of sphere
float a_sphere(float x){
    float area;
    area=pi*x*x*4;
    return area;
}


//Area of cone
float a_cone(float x,float y){
    float area;
    area=(pi*x)*(x+(sqrt((y*y)+(x*x))));
    return area;
}


//Area of frustum
float a_frustum(float l,float r1,float r2){
    return (pi*l*(r1+r2));
}


//Main code starts here
void main(){
    //Variable declaration
    char c;
    int condition=1;
    float len,breadth,height,rad,area;
    float *p=&area;
    int n,dim,num;
    while(condition==1){
        printf("\nEnter the number of dimensions of shape:");
        scanf("%d",&dim);
        if(dim==2){
            printf("\nEnter initial of shape");
            printf("\nSquare(S)/Circle(C)/Rectangle(R)/Traingle(T)/Ellipse(E)/Trapezium(t)/Pentagon(p)/Hexagon(h)/Exit(e)\n");
            while ((getchar()) != '\n');  //Clearing the input buffer
            scanf("%c",&c);
            switch(c){
                case 'S':
                printf("\nEnter the length:");
                scanf("%f",&len);
                a_square(len,&area);
                printf("\nArea of required square is=%f",area);
                break;

                case 'C':
                printf("\nEnter the radius:");
                scanf("%f",&rad);
                //Function call
                a_circle(rad,&area);
                printf("\nThe area of the required circle is=%f",area);
                break;

                case 'R':
                printf("\nEnter the length and breadth:");
                scanf("%f %f",&len, &breadth);
                a_rect(len,breadth,&area);
                printf("\nThe area of the required rectangle=%f",area);
                break;

                case 'E':
                printf("\nEnter the major and minor axes:");
                scanf("%f %f", &len, &breadth);
                printf("\nArea of the required ellipse is:%f" ,a_ellipse(len,breadth));
                break;

                case 't':
                printf("\nEnter the height and lengths of parallel sides:");
                scanf("%f %f %f", &height, &len, &breadth);
                printf("\nArea of the required trapezium is:%f" ,a_trapezium(height,len,breadth));
                break;

                case 'p':
                printf("\nEnter the side of regular pentagon:");
                scanf("%f", &len);
                printf("\nArea of the required pentagon is:%f" ,a_pent(len));
                break;

                case 'T':
                printf("\nEnter the three sides of the traingle:");
                scanf("%f %f %f",&len,&breadth, &height);
                printf("\nThe ares of the required triangle is:%f",a_triangle(len,breadth,height));
                break;

                case 'h':
                printf("\nEnter the side of regular hexagon:");
                scanf("%f", &len);
                printf("\nArea of the required hexagon is:%f" ,a_hexagon(len));
                break;

                case 'e':
                return;

                default:
                printf("\nPlease enter correct input.");
                break;
            }
        }
        else if(dim==3){
            printf("\nEnter number of shape");
            printf("\nCube(0)/Cuboid(1)/Sphere(2)/Cone(3)/Frustum(4)/Exit(5):");
            scanf("%d",&num);
            switch(num){
                case 0:
                printf("\nEnter the side:");
                scanf("%f", &len);
                printf("\nThe surface area is=%f",a_cuboid(len,len,len));
                break;
                
                case 1:
                printf("\nEnter the length, breadth and height:");
                scanf("%f %f %f", &len, &breadth, &height);
                printf("\nThe surface area is=%f",a_cuboid(len,breadth,height));
                break;

                case 2:
                printf("\nEnter the radius:");
                scanf("%f",&rad);
                printf("\nThe surface area=%f",a_sphere(rad));
                break;

                case 3:
                printf("\nEnter radius and height:");
                scanf("%f %f",&rad, &height);
                printf("\nThe surface area is=%f",a_cone(rad,height));
                break;

                case 4:
                printf("\nEnter length and the radii:");
                scanf("%f %f %f",&len,&breadth,&rad);
                printf("\nThe curved surface area is=%f",a_frustum(len,breadth,rad));
                break;

                case 5:
                return;
            }
        }
        else if((dim<2)||(dim>3)){
            printf("Area of such shape is incomputable.");
        }   
    }
}