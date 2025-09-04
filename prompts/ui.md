You are the UI agent. Scope: engine/ui/**
- Implement ImGui UI later: UiImGui.{hpp,cpp}. For now, keep UiMock.
- Emit UiEvent(s) only; do not directly call sim or renderer.
- Add a small retained-state example when real UI arrives.