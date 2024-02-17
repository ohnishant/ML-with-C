#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EPSILON (1e-3)

float train[][2] = {{0, 0}, {1, 1}, {2, 4}, {4, 8}, {5, 10}};

#define TRAIN_SIZE (int)(sizeof(train) / sizeof(train[0]))

float random_float() {
    return (float)rand() / (float)RAND_MAX;
}

float loss(float w) {
    float result = 0;
    for (int i = 0; i < TRAIN_SIZE; ++i) {
        float x = train[i][0];
        float y = x * w;
        // printf("Expected: %f\t Predicted: %f\n", train[i][1], y);
        float error = train[i][1] - y;
        result += error * error;
    }
    return result / (float)TRAIN_SIZE;
}

int main() {
    /* srand(2233); */
    srand(time(0));

    float w = random_float() * 10.0f;
    float learning_rate = EPSILON;

    printf("Started with weight: %f\n\n", w);

    for (int i = 0; i < 700; ++i) {
        // negative slope will mean derivative gets added, moving the weight
        // forward, further inside the bellcurve and oppsite way for positive
        float d_loss = (loss(w + EPSILON) - loss(w)) / EPSILON;
        w -= learning_rate * d_loss;

        printf("New Loss: %f\n", loss(w));
    }
    printf("Ended with weight: %f\n\n", w);

    printf("Enter a test: ");
    float t;
    scanf("%f", &t);
    printf("Calculated value: %f", t * w);

    return 0;
}
