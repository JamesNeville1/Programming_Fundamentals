//Built-in
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h> 

//Mine
#include "utility.h"
#include "event.h"
#include "player.h"
#include "enemy.h"
#include "npc.h"

using namespace std;

#pragma region Unsorted
enum gameState {
	exploring,
	combat,
	dialogue,
	dead,
};
string ReturnTitle() {
	const char* titleScreen = R"(
	BBBBBBBBBBBBBBBBB                     lllllll             d::::::d                                       '::::'                              GGGGGGGGGGGGG                           tttt                                          444444444  
	B::::::::::::::::B                    l:::::l             d::::::d                                       '::::'                           GGG::::::::::::G                        ttt:::t                                         4::::::::4  
	B::::::BBBBBB:::::B                   l:::::l             d::::::d                                       ':::''                         GG:::::::::::::::G                        t:::::t                                        4:::::::::4  
	BB:::::B     B:::::B                  l:::::l             d:::::d                                       ':::'                          G:::::GGGGGGGG::::G                        t:::::t                                       4::::44::::4  
	B::::B     B:::::B  aaaaaaaaaaaaa    l::::l     ddddddddd:::::d uuuuuu    uuuuuu  rrrrr   rrrrrrrrr   ''''       ssssssssss         G:::::G       GGGGGG  aaaaaaaaaaaaa   ttttttt:::::ttttttt        eeeeeeeeeeee            4::::4 4::::4  
	B::::B     B:::::B  a::::::::::::a   l::::l   dd::::::::::::::d u::::u    u::::u  r::::rrr:::::::::r           ss::::::::::s       G:::::G                a::::::::::::a  t:::::::::::::::::t      ee::::::::::::ee         4::::4  4::::4  
	B::::BBBBBB:::::B   aaaaaaaaa:::::a  l::::l  d::::::::::::::::d u::::u    u::::u  r:::::::::::::::::r        ss:::::::::::::s      G:::::G                aaaaaaaaa:::::a t:::::::::::::::::t     e::::::eeeee:::::ee      4::::4   4::::4  
	B:::::::::::::BB             a::::a  l::::l d:::::::ddddd:::::d u::::u    u::::u  rr::::::rrrrr::::::r       s::::::ssss:::::s     G:::::G    GGGGGGGGGG           a::::a tttttt:::::::tttttt    e::::::e     e:::::e     4::::444444::::444
	B::::BBBBBB:::::B     aaaaaaa:::::a  l::::l d::::::d    d:::::d u::::u    u::::u   r:::::r     r:::::r        s:::::s  ssssss      G:::::G    G::::::::G    aaaaaaa:::::a       t:::::t          e:::::::eeeee::::::e     4::::::::::::::::4
	B::::B     B:::::B  aa::::::::::::a  l::::l d:::::d     d:::::d u::::u    u::::u   r:::::r     rrrrrrr          s::::::s           G:::::G    GGGGG::::G  aa::::::::::::a       t:::::t          e:::::::::::::::::e      4444444444:::::444
	B::::B     B:::::B a::::aaaa::::::a  l::::l d:::::d     d:::::d u::::u    u::::u   r:::::r                         s::::::s        G:::::G        G::::G a::::aaaa::::::a       t:::::t          e::::::eeeeeeeeeee                 4::::4  
	B::::B     B:::::Ba::::a    a:::::a  l::::l d:::::d     d:::::d u:::::uuuu:::::u   r:::::r                   ssssss   s:::::s       G:::::G       G::::Ga::::a    a:::::a       t:::::t    tttttte:::::::e                          4::::4  
	BB:::::BBBBBB::::::Ba::::a    a:::::a l::::::ld::::::ddddd::::::ddu:::::::::::::::uu r:::::r                   s:::::ssss::::::s       G:::::GGGGGGGG::::Ga::::a    a:::::a       t::::::tttt:::::te::::::::e                         4::::4  
	B:::::::::::::::::B a:::::aaaa::::::a l::::::l d:::::::::::::::::d u:::::::::::::::u r:::::r                   s::::::::::::::s         GG:::::::::::::::Ga:::::aaaa::::::a       tt::::::::::::::t e::::::::eeeeeeee               44::::::44
	B::::::::::::::::B   a::::::::::aa:::al::::::l  d:::::::::ddd::::d  uu::::::::uu:::u r:::::r                    s:::::::::::ss            GGG::::::GGG:::G a::::::::::aa:::a        tt:::::::::::tt  ee:::::::::::::e               4::::::::4
	BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaallllllll   ddddddddd   ddddd    uuuuuuuu  uuuu rrrrrrr                     sssssssssss                 GGGGGG   GGGG  aaaaaaaaaa  aaaa          ttttttttttt      eeeeeeeeeeeeee               4444444444
	)";

	return titleScreen;
}
#pragma endregion

int main() {
	setEvents();

	//cout << ReturnTitle() << endl;

	playerTemp playersCharacter = playerTemp();
	playersCharacter.characterDetails();

	utils::dialogueBox("Hey, you're finally awake", 1);
	//utils::dialogueBox("You were trying to cross the border, right?", 2);
	//utils::dialogueBox("Walked right into that Imperial ambush, same as me?", 3);

	cout << dialogueEvent(0);
}