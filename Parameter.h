#pragma once

class Parameter
{
private:
    float param_;

public:
    Parameter() = default;
    ~Parameter() = default;
    float GetParameter() { return param_ };
    virtual void TrainParam() = 0;
};

class TrainableParameter : public Parameter
{
private:
public:
    TrainableParameter() = default;
    ~TrainableParameter() = default;
    void TrainParam() { /*TODO: Update parameter*/};
};

class UnTrainableParameter : public Parameter
{
private:
public:
    UnTrainableParameter() = default;
    ~UnTrainableParameter() = default;
    void TrainParam() { /*Do nothing, cannot train*/ };
};