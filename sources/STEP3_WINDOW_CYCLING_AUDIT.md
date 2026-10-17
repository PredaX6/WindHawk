# Étape 3 — Navigation entre fenêtres par la molette

## Objectif

Remplacer le comportement précédent de Taskbar Button Scroll par une navigation entre fenêtres depuis la zone de fond de la barre des tâches. Tous les libellés et descriptions de réglages exposés sont en français.

## Comportement prévu

- Molette vers le bas : réduire la fenêtre active puis afficher la fenêtre suivante.
- Molette vers le haut : réduire la fenêtre active puis afficher la fenêtre précédente.
- Les fenêtres réduites restent dans la liste et sont restaurées lorsqu'elles sont sélectionnées.
- Option de réglage pour activer/désactiver la navigation et option pour inverser le sens.
- Les événements de molette sur les boutons XAML et les aperçus sont consommés afin qu'ils ne déclenchent pas le cycle.

## Détails techniques

- La liste est construite avec `EnumWindows` dans l'ordre Z Windows.
- Les fenêtres invisibles, fenêtres système de la barre des tâches/du bureau, fenêtres utilitaires et fenêtres possédées non marquées `WS_EX_APPWINDOW` sont exclues.
- Les fenêtres réduites visibles restent éligibles.
- La logique est intégrée au hook existant de `CTaskListWnd::v_WndProc`.
- Le réglage `oldTaskbarOnWin11` reste disponible pour ExplorerPatcher.
- Le fichier original `GlassExplorerTaskSwitcher.wh.cpp`, le candidat d'étape 1 et les versions candidates précédentes restent inchangés.

## Validation à effectuer dans Windhawk

1. Compiler le fichier complet `candidates/All in One - étape 3.wh.cpp`.
2. Dans une zone vide de la barre des tâches, faire défiler vers le bas : la fenêtre active doit se réduire et la suivante doit apparaître.
3. Faire défiler vers le haut : la fenêtre active doit se réduire et la précédente doit apparaître.
4. Réduire plusieurs fenêtres avant le test et vérifier qu'elles sont restaurées lorsqu'elles sont sélectionnées.
5. Vérifier que la molette sur les boutons et aperçus ne déclenche pas le cycle.
6. Vérifier les deux sens avec l'option d'inversion activée.
7. Confirmer que les animations continuent de fonctionner.

## État

Candidat généré et contrôlé statiquement. Aucune compilation Windhawk ni validation à l'exécution n'a été effectuée par l'assistant.
