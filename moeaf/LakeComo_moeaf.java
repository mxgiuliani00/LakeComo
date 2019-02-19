import java.io.IOException;

import org.moeaframework.Executor;
import org.moeaframework.core.NondominatedPopulation;
import org.moeaframework.core.Solution;
import org.moeaframework.core.variable.RealVariable;
import org.moeaframework.problem.ExternalProblem;
import org.moeaframework.core.PRNG;


/**
 * Demonstrates how problems can be defined externally to the MOEA Framework,
 * possibly written in a different programming language.
 */
public class LakeComo_moeaf {

	/**
	 * The ExternalProblem opens a communication channel with the external
	 * process.  Some Java methods are required to correctly setup the problem
	 * definition.
	 */
	public static class LakeComoMF extends ExternalProblem {

		public LakeComoMF() throws IOException {
			super("../test/LakeComoSim", "../test/settings_lakeComo_CSPA.txt");
		}

		@Override
		public String getName() {
			return "LakeComo";
		}

		@Override
		public int getNumberOfVariables() {
			return 46;
		}

		@Override
		public int getNumberOfObjectives() {
			return 2;
		}

		@Override
		public int getNumberOfConstraints() {
			return 0;
		}
        
        /**
         * Constructs a new solution and defines the bounds of the decision
         * variables.
         */
        @Override
        public Solution newSolution() {
            Solution solution = new Solution(getNumberOfVariables(), getNumberOfObjectives());
            
            // define decision variable domains
            int j = 0;
            solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // bias
            // 5 RBFs
            for(int i =0; i<5; i++){
                solution.setVariable(j, new RealVariable(-1.0, 1.0)); j++; // center
                solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // radius
                solution.setVariable(j, new RealVariable(-1.0, 1.0)); j++; // center
                solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // radius
                solution.setVariable(j, new RealVariable(-1.0, 1.0)); j++; // center
                solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // radius
                solution.setVariable(j, new RealVariable(-1.0, 1.0)); j++; // center
                solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // radius
                solution.setVariable(j, new RealVariable(0.0, 1.0)); j++; // bias
            }
            
            return solution;
        }
        
        
    }
	
	public static void main(String[] args) {
        
        // MOEA settings: eNSGAII, NFE=1000
        String alg="eNSGAII";
        int nfe=1000;
        // command line settings: seed
        long seed;
        if(args.length > 0){
            try{
                seed = Long.parseLong(args[0]);
                PRNG.setSeed(seed);
            }catch(NumberFormatException e){
                System.err.println("Argument must be a number");
                System.exit(1);
            }
        }
        
        //configure and run the Rosenbrock function
		NondominatedPopulation result = new Executor()
				.withProblemClass(LakeComoMF.class)
				.withAlgorithm(alg)
				.withMaxEvaluations(nfe)
                .withEpsilon(0.5, 5.0)
				.run();
				
		//display the results
		for (Solution solution : result) {
            
            for (int i = 0; i < 46; i++){
                System.out.print(solution.getVariable(i));
                System.out.print(" ");
            }
            System.out.print(solution.getObjective(0));
            System.out.print(" ");
            System.out.println(solution.getObjective(1));
            
		}
	}
	
}
