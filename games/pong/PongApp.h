#pragma once
#include "engine/core/Application.h"


class PongApp : public engine::core::Application {
    public:
        PongApp();
    protected:
        void onStart() override;
        void onUpdate(float deltaTime) override;
        void onRender() override;
        void onTerminate() override;
};