#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6
struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;



void print_all_packages(town t){
    printf("%s:\n",t.name);
    for(int x = 0; x < t.offices_count; x++){
        printf("\t%d:\n",x);
        post_office of = *(t.offices+x);
        for(int j = 0; j < of.packages_count; j++){
            package p = of.packages[j];
            printf("\t\t%s\n",p.id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index){
    post_office *tar = target->offices + target_office_index;
    post_office *src = source->offices + source_office_index;
    int m  = (*tar).min_weight;
    int M = (*tar).max_weight;
    package to_stay[src->packages_count];
    package going[src->packages_count];
    int going_counter = 0;
    int not_going_counter = 0;
    for(int x = 0; x < (*src).packages_count;x++){
        package next = src->packages[x];
        if(next.weight <= M && next.weight >= m){
            going[going_counter]= next;
            going_counter++;
        }else{
            to_stay[not_going_counter] = next;
            not_going_counter++;
        }
    }
    src->packages = (package *)realloc(src->packages,not_going_counter*sizeof(struct package));
    for(int x = 0 ; x < not_going_counter ; x++){
        *(src->packages + x) = to_stay[x];
    }
    tar->packages = (package*)realloc(tar->packages ,(tar->packages_count+going_counter)*sizeof(package));
    for(int x = 0; x < going_counter; x++){
        *(tar->packages+tar->packages_count+x) = going[x];
    }
    tar->packages_count += going_counter;
    src->packages_count -= going_counter;
}

town town_with_most_packages(town* towns, int towns_count){
    int best = -1;
    town best_town = towns[0];
    for(int x = 0; x < towns_count; x++){
        town current_town = towns[x];
        int apack = 0;
        for(int i = 0; i < current_town.offices_count;i++){
            apack += current_town.offices[i].packages_count;
        }
        if(apack > best){
            best_town = current_town;
            best = apack;
        }
    }
    return best_town;
}

town* find_town(town* towns, int towns_count, char* name) {
    for(int x = 0 ; x < towns_count; x++){
        if(!strcmp((*towns).name,name)){
            return towns;
        }
        towns++;
    }
    return NULL;
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
            case 1:
                scanf("%s", town_name);
                town* t = find_town(towns, towns_count, town_name);
                print_all_packages(*t);
                break;
            case 2:
                scanf("%s", town_name);
                town* source = find_town(towns, towns_count, town_name);
                int source_index;
                scanf("%d", &source_index);
                scanf("%s", town_name);
                town* target = find_town(towns, towns_count, town_name);
                int target_index;
                scanf("%d", &target_index);
                send_all_acceptable_packages(source, source_index, target, target_index);
                break;
            case 3:
                printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
                break;
        }
    }
    return 0;
}