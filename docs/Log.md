# igraphic — journal

Marqueurs : 🟢 ajout · 🔴 rupture · 🔵 correctif · ⚪ interne ou doc · 🟡 propose
dans le plan, code non ecrit.

## v0.1.0

- 🟢 `IGraphic2Module`, `IGraphic3Module` (qui derive du premier)
- 🟢 `IWindow2/3`, `IKeyboard`, `IMouse`, `IGamepad`
- 🟢 `ITexture`, `ISprite`, `IFont`, `IText`, `IPolygon`
- 🟢 `ICamera`, `IMesh`, `IModel`, `IAnimationSet`
- 🟢 `isReady()` sur les dix types, `setMouseVisibility(bool)`
- 🟢 `accepts = {"graphic2", "graphic3"}` : la substitution vit dans le
  contrat

## v0.2.0 — propose, rien de tout ceci n'est ecrit

- 🟡 `GraphicAssets` — on lui declarerait des ressources, il les
  refabriquerait quand le vendor change et detruirait dans l'ordre
  inverse
- 🟡 inclure le granulaire (`Vector2.hpp`) au lieu du parapluie `Type.hpp`
