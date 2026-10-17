# Étape 2 — Audit d’intégration Taskbar Button Scroll

## Candidat

- Fichier complet : `candidates/All in One - étape 2.wh.cpp`
- Branche : `work/all-in-one-clean-start`
- Base Windows Animations : conservée à partir du blob connu `784ea1f311ed96ba201f19adfefec631b6c0b7cc`
- Source Taskbar Button Scroll : snapshot original conservé dans `sources/original/taskbar-button-scroll.wh.cpp`
- Compilation Windows/Windhawk : non exécutée par l’assistant ; la validation reste à faire par compilation et test utilisateur.

## Changements

- Ajout des paramètres Taskbar Button Scroll dans le bloc de réglages existant, sans réutiliser les noms de réglages des animations.
- Ajout des dépendances d’en-tête et options de liaison requises par le composant.
- Isolation de l’implémentation dans le namespace `TaskbarButtonScroll` afin d’éviter les collisions de symboles.
- Renommage des callbacks du composant en fonctions internes `Init`, `AfterInit`, `Uninit` et `SettingsChanged`, puis orchestration via les callbacks Windhawk uniques.
- Initialisation du composant uniquement dans `explorer.exe`; les autres processus gardent les animations Windows sans installer les hooks de barre des tâches.
- Le callback global de changement de paramètres transmet la demande de rechargement lorsque `oldTaskbarOnWin11` change.
- Le fichier de référence de l’étape 1 n’a pas été modifié ; ce candidat est un fichier séparé.

## Ordre de test demandé

1. Compiler ce fichier complet dans Windhawk.
2. Vérifier que les animations existantes fonctionnent comme avant.
3. Vérifier la molette sur un bouton de barre des tâches et sur un aperçu de fenêtre.
4. Vérifier les options sens inverse et agrandir/restaurer.
5. Vérifier que le changement de `oldTaskbarOnWin11` provoque le rechargement attendu.
6. Désactiver temporairement les deux options Taskbar Button Scroll et vérifier que les animations restent fonctionnelles.

## Limites

Les scans statiques ne prouvent pas la compatibilité ABI des hooks, la compilation, ni le comportement à l’exécution. Si la compilation échoue, fournir le journal complet ; si elle réussit, tester les cas ci-dessus avant de considérer cette étape stable.
