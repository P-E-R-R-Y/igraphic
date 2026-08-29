# Igraphic

version: 0.2.0

> Contrats graphiques : fenetre, dessin 2D et 3D, entrees.

[![Docs](https://img.shields.io/badge/docs-doxygen-blue.svg)](https://p-e-r-r-y.github.io/igraphic)

Deux contrats chargeables separement, pas un module monolithique : un
vendor implemente `IGraphic2Module` seul s'il ne sait dessiner qu'en 2D, ou
`IGraphic3Module` (qui l'etend) s'il sait aussi faire de la 3D. Aucun
vendor n'est jamais force de simuler une capacite qu'il n'a pas.

## IGraphic2Module

- window -> `IWindow2`
- texture -> `ITexture`
- font -> `IFont`
- polygon -> `IPolygon`
- sprite -> `ISprite`, construit depuis une `ITexture`
- text -> `IText`, construit depuis une `IFont`

## IGraphic3Module (etend IGraphic2Module)

- window -> `IWindow3`, qui EST une `IWindow2` : elle dessine la 2D aussi
- camera -> `ICamera`
- mesh -> `IMesh`
- animation set -> `IAnimationSet`
- model -> `IModel`, construit depuis un `IMesh`, texture par une
  `ITexture`, anime par un `IAnimationSet`

## Les trois fenetres

- `IWindow` - cycle de vie et entrees natives, independant de toute
  capacite de dessin. C'est elle qui donne `IKeyboard`, `IMouse`, `IGamepad`.
- `IWindow2 : IWindow` - ajoute le dessin 2D.
- `IWindow3 : IWindow2` - ajoute le dessin 3D.

## Ressources chargees et objets qui les referencent

`ITexture`, `IFont`, `IMesh` et `IAnimationSet` portent la donnee chargee.
`ISprite`, `IText` et `IModel` n'en portent qu'une reference : supprimer
tous les sprites d'une texture ne supprime pas la texture, seul
`deleteTexture()` le fait.

## Ce qui n'est pas ici

- l'audio -> [iaudio](https://github.com/P-E-R-R-Y/iaudio), sans couplage a
  une fenetre (`InitAudioDevice()` n'a besoin d'aucun `InitWindow()`), donc
  contrat separe et chargeable a part
- le chargement des vendors -> [imodule](https://github.com/P-E-R-R-Y/imodule).
  Ce repo ne charge rien : il ne contient que des interfaces.
