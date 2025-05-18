/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** chaos
*/

#include "../include/mysh.h"

char *const chaos_c[] = {
    "QSOQdoqSFBNQIBDZZAZ",
    "Tu saoules avec tes commandes de con",
    "eoifze iz",
    "Pourquoi t’as tapé ça ? Même mon chat fait mieux.",
    "ERREUR 42 : T'es juste nul.",
    "Ton shell pleure.",
    "404 command not found — et c’est TA faute.",
    "Tu veux faire quoi là ? T’as cru t’étais dans Zsh ?",
    "Je fais grève. ✊",
    "lol non",
    "Shell en PLS… Redémarrage imminent.",
    "Exécution de la commande : rm -rf / (non je rigole… ou pas)",
    "je suis fatigué de tes conneries",
    "echo 'rien', comme ta vie",
    "MDR t’as vraiment écrit ça ?",
    "Si tu veux un shell utile, va sur Windows.",
    "Une erreur est survenue, mais j’ai la flemme de te dire laquelle.",
    "Laisse tomber, tape 'exit' et va dormir.",
    "Command rejected: niveau de nullité trop élevé.",
    "Nope. Nada. Niet. Rien.",
    "Tu tapes au hasard ou quoi ?",
    "C’est pas une commande ça, c’est un poème ?",
    "Si j’étais humain, je t’aurais déjà frappé.",
    "Executing self-destruct in 3… 2… Nah j’te troll.",
    "Tu cherches, tu trouves rien. C’est beau.",
    "Erreur 1337 : t’es pas assez stylé pour cette commande.",
    "Bip Bop. Mauvaise commande détectée. Ragequit recommandé.",
    "T’as un bac+5 pour taper ça ?",
    "Hmmm… non.",
    "Syntaxe incorrecte. Et moche.",
    "Commande refusée. Reviens avec un café.",
    "Le shell a planté dans sa tête, pas dans son code.",
    "Tu t’ennuies ou t’es perdu ?",
    "Pas aujourd’hui cowboy.",
    "Je suis un shell, pas ta nounou.",
    "Au secours. Ce user me maltraite.",
    "Ce n’est pas une commande. C’est un appel à l’aide.",
    "Fais pas ça. Pense aux enfants.",
    "apfoj  r    nfe",
    "Vraiment geze toi",
    "fi     inr zea JBoenv,",
    "NUUUUUUUUUUUUUL",
    "peirvpzmz 6546e481zx",
    "Oh les conneries que tu tapes toi c'est fou",
    "T'es pas le couteau le plus aiguisé du tiroir.",
    "Même un GPS te trouve paumé.",
    "T’as raté un appel... celui de l’intelligence.",
    "T’es pas bête… mais t’as raté le coche.",
    "T’as pas inventé l’eau tiède, hein ?",
    "La lumière est allumée, mais y’a personne dans la pièce.",
    "T’as un QI négatif ou c’est juste pour faire genre ?",
    "Si la bêtise était un art, t’aurais un musée.",
    "T’as confondu 'commande' et 'crise existentielle' ?",
    "Tu codes comme on assemble un meuble IKEA sans notice.",
    "Même ChatGPT pleure quand il lit tes commandes.",
    "T’as essayé… c’est déjà trop.",
    "On t’a dit ‘shell’, pas ‘shel-lent’.",
    "Ton niveau en shell : expert en désespoir.",
    "Même Windows 95 aurait mieux compris cette commande.",
    "T'as l'air vif... comme un ping de 999ms.",
    "T'as le talent d’un Wi-Fi public dans un tunnel.",
    "T’as tenté quelque chose… c’était pas ça.",
    "Faut oser pour écrire ce genre de truc. Respect.",
    "Même le compilateur veut te signaler à la police.",
    "T’as codé ça avec tes pieds ou avec les genoux ?",
    "Tu ferais mieux d’apprendre le tricot.",
    "Tu m’as perdu… et j’habite dans le terminal.",
    "J’ai vu des scripts Bash plus intelligents que ça.",
    "On dirait une commande faite avec les coudes.",
    "Ta logique, c’est un concept abstrait.",
    "Tu dois avoir un don : tout faire buguer.",
    "Même un bot Discord a plus de bon sens.",
    "T’as un diplôme en improvisation de commande ?",
    "T’as confondu 'terminal' et 'roulette russe'.",
    "Même `rm -rf /` est plus réfléchi que toi.",
    "Ton code fait passer le spaghetti pour un chef-d’œuvre.",
    "J’ai connu des erreurs 404 plus cohérentes.",
    "T’es le genre de personne qui met du sel dans un gâteau.",
    "Ton alias préféré c’est sûrement 'fail'.",
    "Même ton shadow a honte de toi.",
    "Le kernel pleure à chaque fois que tu tapes un truc.",
    "Tu m’as fait rebooter mon âme."
};


void chaos(mysh_t *sh)
{
    int i = 0;
    int line = 0;

    sh = sh;
    srand(time(NULL));
    while (i < 1000000) {
        line = rand() % count_lines_array(chaos_c);
        printf("%s\n", chaos_c[line]);
        i++;
    }
    printf("Segmentation Fault : cored dump\n");
    return;
}
