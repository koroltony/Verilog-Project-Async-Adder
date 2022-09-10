//new module to test Async capabilities of testbench

module asyncadder #(parameter WIDTH1=8)(input wire [WIDTH1-1:0] a,
input wire [WIDTH1-1:0] b, output reg [WIDTH1:0] y);

    always @(*) begin
        y=a+b;
    end
endmodule
