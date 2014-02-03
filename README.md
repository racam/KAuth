K-Auth
======

INSTALL & COMPILING
-------------------
See the file INSTALL (english only)


[EN] What is K-Auth ?
----------------
K-Auth is a simple software for Web authentification. It will sign the text in your clipboard with a private RSA key.

[FR] Qu'est-ce que K-Auth ?
---------------------------
K-Auth est un logiciel simple d'utilisation permettant une authentification Web. Son rôle est de signer le texte enregistré dans votre Presse-papier avec une clef privée de type RSA.



[EN] What is it for ?
-------------------
Nowadays, Web authentification become less and less secure. Most of the passwords are the same and non-secure. If someone find your, there is a high probability that he can log into many website with your account.

K-Auth wants to improve this lack of security. In fact, with K-Auth who can :
* You don't have to remember any password.
* K-Auth is like a [one-time password](http://en.wikipedia.org/wiki/One-time_password) : an authification is valid for only one login session or transaction.
* There no password (even hashed) store in the website BDD.
* There is not a third person who manage your authentification : Google / Facebook / OpenID ...

[FR] A quoi cela sert-il ?
--------------------------
De nos jours, l'authentification web est de moins en moins sécurisée. La plupart des mots de passes sont redondants et peu sécurisés. Si quelqu'un trouve le votre, il y a une grande probabilité que cette personne puisse se connecter sur plusieurs site avec votre compte.

K-Auth veut combler se manque de sécurité. En effet avec K-Auth vous avez la possibilité de :
* Ne pas avoir à retenir de mots de passes.
* K-Auth est comme un [mot de passe unique](http://fr.wikipedia.org/wiki/Mot_de_passe_unique) : une authentification n'est valable que pour une session ou une transaction.
* Il n'y a pas de mots de passes (même hashés) enregistrés dans la base de données du site Web.
* Il n'y aucun tiers qui gère vos données personnelles pour votre authentification : Google / Facebook / OpenID ...



[EN] How doest it work ?
------------------------
K-Auth bases himself on the asymmetric cryptology of the RSA type. Indeed, with a private key you can sign data so as to certify in a certain way their intégritées as well as the author of this signature.
For that purpose, only a public key bound to the private key can certify these signatures.

K-Auth thus bases himself on this concept to give a safe authentification:
1. When we want to authenticate, the Web server gives a small single-use word: "abcd" for example.
2. We copy (CTRL+C) this word in the clipboard.
3. We open the KAuth software in the systray, and we press the button which generates the signature of word "abcd" and place it in the clipboard.
4. We paste (CTRL+V) the signature in the reserved field for that purpose on the Web site.
5. The Web server, tries to certify the word "abcd" with the signature and the public key in BDD.
6. The Web server manages to certify the word with the public key, and authorizes the connection of the user.


[FR] Comment cela marche-t-il ?
-------------------------------
K-Auth se base sur la cryptologie asymétrique du type RSA. En effet, avec une clef privée vous pouvez signer des données de façon à certifier de façon certaine leurs intégrités ainsi que l'auteur de cette signature.
Pour cela, seule une clef publique liée à la clef privée peut certifier ces signatures.

K-Auth se base donc sur ce concept pour donner une authentification sûre :
1. Quand on veut s’authentifier, le serveur web donne un petit mot à usage unique : « abcd » par exemple.
2. On copie (CTRL+C) ce mot dans le presse-papier.
3. On ouvre le logiciel KAuth dans la barre de tâche, et on appuit sur un bouton qui génère la signature de mot « abcd » et la place dans le presse-papier.
4. On colle (CTRL+V) la signature dans le champ réservé à cet effet sur le site web.
5. Le serveur web, essaye de certifier le mot « abcd » avec la signature et la clef publique en BDD.
6. Le serveur web arrive à certifier le mot avec la clef publique, et autorise la connexion de l’utilisateur.

