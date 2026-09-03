# igraphic — changelog

Markers: 🟢 added · 🔴 breaking · 🔵 fix · ⚪ internal or docs · 🟡 proposed
in the plan, no code written yet.

## v0.1.0

- 🟢 `IGraphic2Module`, `IGraphic3Module` (which derives from the first)
- 🟢 `IWindow2/3`, `IKeyboard`, `IMouse`, `IGamepad`
- 🟢 `ITexture`, `ISprite`, `IFont`, `IText`, `IPolygon`
- 🟢 `ICamera`, `IMesh`, `IModel`, `IAnimationSet`
- 🟢 `isReady()` on all ten resource types, `setMouseVisibility(bool)`
- 🟢 `accepts = {"graphic2", "graphic3"}`: substitutability lives in the
  contract

## v0.2.0 — proposed, none of this is written

- 🟡 `GraphicAssets` — you would declare resources to it, it would
  rebuild them when the vendor changes and tear down in reverse order
- 🟡 include the granular header (`Vector2.hpp`) instead of the umbrella
  `Type.hpp`
