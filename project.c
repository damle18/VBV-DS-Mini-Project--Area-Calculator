#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi 3.14

void a_square(float x, float *ptr){
    *ptr=x*x;
}

void a_circle(float x, float *ptr){
    *ptr=pi*x*x;
}

void a_rect(float x, float y, float *ptr){
    *ptr=x*y;
}

float a_cuboid(float x,float y, float z){
    float area;
    area=2*((x*y)+(y*z)+(z*x));
    return area;
}

float a_sphere(float x){
    float area;
    area=pi*x*x*4;
    return area;
}

float a_cone(float x,float y){
    float area;
    area=(pi*x)*(x+(sqrt((y*y)+(x*x))));
    return area;
}


/*void main(){
    char str[10];
    printf("Enter the name of a regular shape:");
    scanf("%s",&str);
    if((strcmp(str,"Square")) || (strcmp(str,"square")) || (strcmp(str,"SQUARE"))){
        float len;
        printf("\nEnter the length:");
        scanf("%f",&len);
        printf("\nArea of required square is=%f",a_square(len));
    }
    else if ((strcmp(str,"Circle")) || (strcmp(str,"circle")) || (strcmp(str,"CIRCLE")))
    {
        float rad;
        printf("Enter the radius:");
        scanf("%f",&rad);
        printf("The area of the required circle is=%f",a_circle(rad));
    }
    
}*/
void main(){
    char c;
    float len,breadth,height,rad,area;
    float *p=&area;
    int n,dim,num;
    printf("Please enter number of test cases:");
    scanf("%d",&n);
    while(n--){
        printf("\nEnter the number of dimensions of shape:");
        scanf("%d",&dim);
        if(dim==2){
            printf("\nEnter initial of shape");
            printf("\nSqaure(S)/Circle(c)/Rectangle(R)\n");
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
                a_circle(rad,&area);
                printf("\nThe area of the required circle is=%f",area);
                break;

                case 'R':
                printf("\nEnter the length and breadth:");
                scanf("%f %f",&len, &breadth);
                a_rect(len,breadth,&area);
                printf("\nThe area of the required rectangle=%f",area);
                break;

                default:
                printf("\nPlease enter correct input.");
                break;
            }
        }
        else if(dim==3){
            printf("\nEnter number of shape");
            printf("\nCuboid(1)/Sphere(2)/Cone(3):");
            scanf("%d",&num);
            switch(num){
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
            }
        }
        else if((dim<2)||(dim>3)){
            printf("Area of such shape is incomputable.");
        }   
    }
}