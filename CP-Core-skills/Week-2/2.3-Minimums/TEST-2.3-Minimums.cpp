#define CATCH_CONFIG_MAIN

#include "../../../catch.hpp"
#include "2.3-Minimums.h"
#include <functional>
#include "../../../Testing/misc.h"

using namespace std;

TEST_CASE("Solution") {

    auto[input, expected] =
    GENERATE(table<string, string>({
                                           {"4\n 3 1 2 3",   "16"},
                                           {"3\n 7 10 10",   "51"},
                                           {"1006\n 130048 403886 544110 972855 823779 791465 879712 619400 332783 470642 845084 600443 977124 468089 915500 344603 486772 48256 57164 427781 651462 66720 754476 775851 351796 608387 712434 704211 179021 787243 451509 557846 49044 839594 459587 730977 879487 488168 287836 193847 505785 231009 185972 636268 774240 575844 385973 143148 365831 101333 710459 255666 735989 804203 37718 930897 147493 864179 620555 603375 290692 116683 756563 581701 715638 626152 495387 975968 269394 112720 513859 575331 46561 301921 212831 995139 383843 95944 618425 202569 356618 949067 784972 276564 806076 888512 688331 791380 228565 346195 232216 428560 40611 130308 530701 709409 141480 587622 725879 942325 944028 755362 261653 419149 232041 222450 783837 390207 357101 447334 980664 766004 469243 838242 462210 337387 797274 626142 259723 100277 356804 910629 211800 675767 914985 739223 79970 101995 250730 282791 299349 918623 387806 391773 550227 795380 120272 903124 281071 918560 839294 69757 601587 820845 893724 640091 679898 335735 686991 337541 974358 242866 728307 743848 485899 685730 860694 727298 110354 772130 236858 118440 877175 15070 144535 955009 856252 435992 142166 363016 834260 462438 223063 400845 504360 138290 404268 823093 309334 941945 745564 662902 903916 760781 575265 426716 701297 956691 802026 503879 823709 900102 768154 75690 611613 908594 910663 572942 117520 946489 147516 449485 551628 352466 731127 377239 843225 576517 149291 624752 606196 530736 629311 291120 562382 321541 441102 402754 969803 42249 52581 297765 86212 782551 281481 236590 707909 23707 927598 609860 774607 125912 666944 736419 128983 312995 258654 479450 875909 576101 506842 414477 577015 158172 400314 268339 952635 202650 550970 956568 567768 992581 736648 229853 493958 435670 699207 484851 624305 957658 110029 420452 963450 760436 161636 382282 465910 268761 580492 230614 796973 171218 413624 87178 740060 533117 299149 882943 806900 477837 421414 193440 280600 352774 11602 28397 211619 709826 702484 969786 286240 341358 239266 744045 788688 356301 698599 310851 665320 763828 732546 659787 146000 33932 363845 718505 219173 346836 958902 271189 346103 246621 578769 310106 432076 989772 482180 323479 493915 147675 501361 285377 704402 425687 355952 292319 966993 777379 553034 449485 385261 733173 314751 414970 966382 314388 249665 147177 338768 438688 339063 108340 354054 533322 493499 800516 969586 55255 616732 916250 848943 969953 657309 609546 448584 967638 661428 286971 971965 8439 891084 829096 976773 316826 202627 228769 510215 412841 576749 156619 420576 697441 133391 660316 481312 33172 100004 626528 4876 394535 650076 295223 552542 515541 795032 147604 421760 857194 482159 324799 675093 757256 556205 492628 697393 918693 590606 674050 67291 288331 606919 465486 670610 884184 509950 406669 878085 391547 869261 879149 682202 768701 805891 837356 622504 159477 646818 787679 364284 388435 609250 141933 586392 416854 81709 264850 337583 826838 116513 75613 836267 528187 729745 884081 273000 465859 969732 721864 724662 924864 288053 395243 193050 168152 715729 911419 50445 241220 280892 378284 219772 780817 633228 649924 114758 473762 741516 220321 114305 400747 38843 567664 876982 140152 504715 755639 237152 304612 122146 354828 431665 416354 224348 169371 553678 387000 180807 852131 502158 46079 208421 965306 244094 435300 641326 141253 703008 981674 868043 128129 322663 142374 167004 773821 54908 553730 498547 269149 788285 979898 923863 79897 406905 474082 380930 902331 780597 853150 799843 449253 266986 506536 325021 39625 18244 120333 887174 912111 30308 878704 489257 332786 330335 530758 718661 507203 504510 611673 889227 454629 179516 634246 139491 861551 706379 394878 938152 536717 572751 719240 750951 918976 512161 405501 468517 579865 298061 646411 372246 432450 920276 229747 79974 370357 521195 287308 728692 261314 52410 16957 955794 40078 463007 12870 998471 170447 307816 660664 435469 359441 577628 629304 973843 979699 61171 959040 357691 138859 543641 479966 686941 256382 344815 59892 667779 66057 161290 562678 843499 711163 141746 4335 853384 519640 571172 657340 741633 898743 325521 112463 482353 824517 370525 64621 626661 204417 5857 853361 349409 496317 317929 733127 795740 526755 727414 24689 969279 989230 849149 494406 896233 146221 799462 303854 380398 31043 795854 8231 136659 743914 276421 449091 48020 242283 877073 178152 620831 650087 136873 301518 467990 555793 622267 429701 468113 452530 780711 395244 317146 465060 907778 582907 693615 389592 235604 459386 438339 108560 922330 933320 848509 18469 642820 151765 502135 15490 868664 525736 828480 273063 548302 644249 230107 771175 493969 678936 207102 241642 102148 637477 46164 148140 384219 933909 626235 163196 107710 495444 824583 235774 431498 621789 564797 583017 828367 839364 584601 101962 944083 61676 25480 649472 191821 721489 830575 8189 72363 818176 523810 215499 457164 291610 833197 69253 915143 823573 780431 523097 337187 182522 437690 273485 178013 54120 574677 466871 970213 981456 149178 514692 783392 391607 625272 818546 788263 957047 297041 328277 914247 981822 662269 427030 415424 49869 30054 916975 94022 293562 354730 96240 604995 494702 596189 861182 846611 95272 531716 705358 799238 699193 682522 744686 295841 596678 67535 229565 948765 120585 33540 558510 964199 937040 778192 581321 374367 497661 159870 316138 100313 302852 512077 649344 268894 144880 773422 543119 638124 536670 30410 766575 361586 181248 87610 590858 750037 264603 386125 961058 121390 180233 88645 689737 862538 113336 890394 547686 739560 637290 280309 265463 522111 998131 952694 192074 103797 656638 21935 171778 171433 677576 623591 764184 95594 48931 545945 131736 536509 835509 446450 576736 9755 7030 356246 995364 147312 889398 810139 96685 852510 258388 192716 446357 829304 82312 161511 805580 492871 242266 589728 490198 648201 949416 733468 639499 140012 951012 826999 318934 383768 13204 772670 29495 670562 481681 425654 717121 564634 335432 659539 376732 752958 771708 578370 794116 506308 905666 628383 742920 740372 78723 486079 406988 543244 297789 984232 764743 894778 576195 311572 825542 221349 921912 253938 379431 224581 589464 255973 410399 328966 497264 682307 877685 114186 254881 915671 98692 154468 476961 307487 194557 965277 570617 820430 248482 695986 776840 951947 42381 812692 807038 513585 6823 917543 613666 502733 312113 928963 973005 230307 856574 790838 98861 399658 708855 697985 134531 974155 475414 836758 766181 8549 260715 622945 432701 725964 653530 676156 387143 78726 329115 504312 752535 606221 403833 850075 894865 941711 345172 628573 576047 766705 509215 17066 838655 395464 214690 947555 33442 958238 640697 537949 186511 732531 106963 713952 108877 942778 921396 882729 765436 841047 729459 789288 745997 931496 815229 286083 168581 514681 563664 816081 45311 322702 529729 821344 182695 792477 315830 182832 165439 59153 936749 357622 333213 438728 770291",  "6886056300"},
                                    
                                   }));
    SECTION("Short") {
        auto answer = getAnswer(input, &func);

        INFO("Input: " + input);
        REQUIRE(expected == answer);
    }
}
