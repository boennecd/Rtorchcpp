#include <torch/torch.h>

double add(double const x, double const y){
  double dat[] = {x , y};
  torch::Tensor tdat = torch::from_blob(dat, {2}, torch::kFloat64);
  auto su = tdat[0] + tdat[1];
  return su.item<double>();
}
