#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


/***********************************************************
* describe：
*        @internal page: menu page,only show menu name.
*        @out page: implementation page，draw the data page。
*
************************************************************/



/*****current page*****/
tenMenuPage currentpage = 0;
/*****last page*****/
tenMenuPage lastpage = 0;
/*****current menu*****/
tenMenuId currentmenu = 0;
/*****last menu*****/
tenMenuId lastmenu = 0;

int main(int argc, char** buf)
{

    /*******enter the first page and initial global variable******/
    menupagedraw(nenTopMenuStart, nenTopMenuEnd);
    currentpage = nenTopLevel;
    currentmenu = nenTopMenu;
    /*******according key value to choose next action******/
    char a = 0;
    scanf("%c", &a);
    while(a != KEY_KILL){
        switch(a){
            case KEY_BACK:{
                /****currentmenu is internal page's menu & out page is internal page****/
                if(currentmenu != nenNone && menuarray[currentmenu].out != nenNone){
                    /****out page is internal page****/
                    if(menuarray[currentmenu].out < nenTotalMenuPage){
                        currentpage = menuarray[currentmenu].out;
                        currentmenu = pagearray[currentpage].pagefirstmenu;
                        menupagedraw(pagearray[currentpage].pagefirstmenu, pagearray[currentpage].pageendmenu);
                    /****out page is extern page & currenpage is internal page****/
                    } else if(menuarray[currentmenu].out > nenTotalMenuPage && currentpage < nenTotalMenuPage){
                        lastpage = currentpage;
                        currentpage = menuarray[currentmenu].out;
                        lastmenu = currentmenu;
                        currentmenu = nenNone;
                        system("cls");
                        externpagepointer[currentpage - nenTotalMenuPage - 1]();
                    }
                }
                break;
            }
            case KEY_OK:{
                /****currentmenu is internal page menu****/
                if(currentmenu != nenNone){
                    /****ok page is internal page ****/
                    if(menuarray[currentmenu].ok < nenTotalMenuPage){
                        currentpage = menuarray[currentmenu].ok;
                        currentmenu = pagearray[currentpage].pagefirstmenu;
                        menupagedraw(pagearray[currentpage].pagefirstmenu, pagearray[currentpage].pageendmenu);
                    /****current page is internal page & ok page is out page****/
                    } else if (menuarray[currentmenu].ok > nenTotalMenuPage && currentpage < nenTotalMenuPage){
		                lastpage = currentpage;
                        currentpage = menuarray[currentmenu].ok;
	                    lastmenu = currentmenu;
                        currentmenu = nenNone;
                        system("cls");
                        externpagepointer[currentpage - nenTotalMenuPage - 1]();
                    }
                }
                break;
            }
            case KEY_UP:{
                if(currentmenu != nenNone){
                    /****while current menu is the first menu****/
                    if (currentmenu == pagearray[currentpage].pagefirstmenu){
                        currentmenu = pagearray[currentpage].pageendmenu;
                        /****while current menu is not the first menu****/
                    } else {
                        currentmenu--;
                    }
                    menupagedraw(pagearray[currentpage].pagefirstmenu, pagearray[currentpage].pageendmenu);
                }
                break;
            }
            case KEY_DOWN:{
                if(currentmenu != nenNone){
                    /****while current menu is the end menu****/
		        if (currentmenu == pagearray[currentpage].pageendmenu){
			        currentmenu = pagearray[currentpage].pagefirstmenu;
                    /****while current menu is not the end menu****/
		        } else {
	                currentmenu++;
                }
	            menupagedraw(pagearray[currentpage].pagefirstmenu, pagearray[currentpage].pageendmenu);
		        }
                break;
            }
            default:
	        break;
        }
        scanf("%c", &a);
    }
    return 0;
}

/****extern page back to internal page****/
void backtolastpage(){
    if(currentpage > nenTotalMenuPage){
        currentpage = lastpage;
	    currentmenu = lastmenu;
	    menupagedraw(pagearray[currentpage].pagefirstmenu, pagearray[currentpage].pageendmenu);
    }
}
void menupagedraw(tenMenuId menustart, tenMenuId menuend){
    system("cls");
    /****normal menu****/
    #if (NORMAL_THEME == 1)
        /****the total number of currentpage's menu****/
	int totalmenunumber = menuend - menustart + 1;
	/****the internal entry page requires paging number****/
	int totalpagenumber = totalmenunumber / MENU_NUMBER;
	/****the internal page id of the current menu****/
	int currentpageid = (currentmenu - menustart) / MENU_NUMBER;
	/****the first menu item to display on the current page****/
	int currentpagestart = 0;
	/****the last menu item to display on the current page****/
	int currentpageend = 0;
	/****if the current page id equal to the last page id and both belong to the first page****/
	if (currentpageid == 0 && totalpagenumber == currentpageid){
	    currentpagestart = menustart;
	    currentpageend = menuend;
	}
	/****if the current page is the first page and the total page number is not only one page****/
	else if (currentpageid == 0){
	    currentpagestart = menustart;
	    currentpageend = currentpagestart + MENU_NUMBER - 1;
	}
	/****if the current page is the last page****/
	else if (currentpageid != 0 && currentpageid == totalpagenumber){
	    currentpagestart = menustart + MENU_NUMBER * currentpageid;
	    currentpageend = menuend;
	}
	/****if the current page is normal page****/
	else {
	    currentpagestart = menustart + MENU_NUMBER * currentpageid;
	    currentpageend = currentpagestart + MENU_NUMBER - 1;
	}
	/**********draw all the menu names in the current page***********/
	int index = 0;
	for (index = currentpagestart; index <= currentpageend; index++){
	    if (index == currentmenu){
	        printf(">> %s\n", menudataarray[index].drawself);
	    }
	    else{
		printf("   %s\n", menudataarray[index].drawself);
	    }
	}
        printf("\ninput:'q' to back,'o' enter into,'w' move up,'s' move down,'k' to shut down\n");
    /****round menu****/
    #elif (ROUND_THEME == 1)

    #endif
}

