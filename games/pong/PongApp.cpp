#include "PongApp.h"
#include <iostream>

PongApp::PongApp() : Application(engine::core::AppConfig{"Pong", 800,600}){}

void PongApp::onStart() {
    std::cout << "Pong started\n";
}

void PongApp::onUpdate(float deltaTime) {

}

void PongApp::onRender() {

}

void PongApp::onTerminate() {

}