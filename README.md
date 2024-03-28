# wordle_suhayl_nawool_yann_noumi_yonta



Ce projet vise à implémenter un programme en langage C qui permet de résoudre le jeu Wordle en filtrant une liste de mots pour trouver la solution.

Installation
Clonez ce dépôt sur votre machine locale :

bash
Copy code
git clone https://github.com/votre-utilisateur/wordle-solver.git
Assurez-vous d'avoir un compilateur C installé sur votre système. Si vous utilisez Linux, vous pouvez installer GCC avec la commande suivante :

arduino
Copy code
sudo apt-get install gcc
Naviguez vers le répertoire du projet :

bash
Copy code
cd wordle-solver
Compilation
Compilez le programme en utilisant GCC :

css
Copy code
gcc main.c -o wordle_solver
Exécution
Exécutez le programme compilé en utilisant la commande suivante :

bash
Copy code
./wordle_solver
Le programme vous permettra d'entrer les filtres pour trouver la solution du Wordle.

Fonctionnalités
Filtrage par lettre : Vous pouvez filtrer la liste de mots pour n'afficher que ceux contenant une lettre spécifique.
Filtrage par lettres : Vous pouvez filtrer la liste de mots pour n'afficher que ceux contenant plusieurs lettres spécifiques.
Exclusion de lettres : Vous pouvez filtrer la liste de mots pour exclure ceux contenant certaines lettres.
Filtrage par sous-chaîne : Vous pouvez filtrer la liste de mots pour n'afficher que ceux contenant une sous-chaîne spécifique.
