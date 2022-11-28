#include "NodeBase.hh"

class NodeGPInput : public NodeBase {
public:
    NodeGPInput() : NodeBase("gpi", NodeContext::Sensor, 100) {
        for (int i = 2; i <= 16; i++) {
            gpio_init(i);
            gpio_set_dir(i, GPIO_IN);
        }
    }

    void activate(Params &params) override {
        gpio_put(atoi(params["which"].c_str()), atoi(params["state"].c_str()));
        printf("%d\n", gpio_get(28));
    }

    void deactivate(Params &params) override {
        gpio_put(atoi(params["which"].c_str()), 0);
    }

    void setParamFormat(ParameterList &params) override {
        params["which"].strictHints = true;
        params["state"].strictHints = true;

        params["which"].description = "Which GPIO pin to set";
        params["state"].description = "Should the GPIO pin be high or low?";

        params["which"].addHint("2", "GP2");
        params["which"].addHint("3", "GP3");
        params["which"].addHint("4", "GP4");
        params["which"].addHint("5", "GP5");
        params["which"].addHint("6", "GP6");
        params["which"].addHint("7", "GP7");
        params["which"].addHint("8", "GP8");
        params["which"].addHint("9", "GP9");
        params["which"].addHint("10", "GP10");
        params["which"].addHint("11", "GP11");
        params["which"].addHint("12", "GP12");
        params["which"].addHint("13", "GP13");
        params["which"].addHint("14", "GP14");
        params["which"].addHint("15", "GP15");
        params["which"].addHint("16", "GP16");

        params["state"].addHint("1", "High");
        params["state"].addHint("0", "Low");
    }

    Status validateParams(Params &params) override {
        return Status(true);
    }
};

int main() {
    NodeGPInput node;
    node.run();
}